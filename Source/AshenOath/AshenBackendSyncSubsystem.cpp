// Copyright Phoenix Protocol / Ashen Oath. All rights reserved.
#include "AshenBackendSyncSubsystem.h"
#include "AshenSoulConstellationSubsystem.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "JsonObjectConverter.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"
#include "Misc/DateTime.h"
#include "Misc/Guid.h"
#include "Misc/Paths.h"
#include "HAL/PlatformFilemanager.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "HAL/IConsoleManager.h"
#include "Async/Async.h"
#include "TimerManager.h"
#include "Misc/FileHelper.h"
#include "Dom/JsonObject.h"
#include "Dom/JsonValue.h"

DEFINE_LOG_CATEGORY(LogAshenBackendSync);

void UAshenBackendSyncSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);

    if (UGameInstance* GI = GetGameInstance())
    {
        if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
        {
            Kernel->OnStateVectorInvalidated.AddDynamic(this, &UAshenBackendSyncSubsystem::HandleStateVectorInvalidated);
            bIsInitialized = true;
            UE_LOG(LogAshenBackendSync, Log, TEXT("UAshenBackendSyncSubsystem initialized and bound to Soul Constellation Kernel."));
        }
    }
    else
    {
        UE_LOG(LogAshenBackendSync, Warning, TEXT("UAshenBackendSyncSubsystem initialized without a valid GameInstance."));
    }

    // Prepare retry cache directory before used by any async path.
    RetryCacheDir = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("BackendSyncCache"));
    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
    if (!PlatformFile.DirectoryExists(*RetryCacheDir))
    {
        PlatformFile.CreateDirectoryTree(*RetryCacheDir);
    }

    // Register console commands for retry cache management.
    InspectCacheConsoleCommand = MakeUnique<FAutoConsoleCommand>(
        TEXT("AshenBackendSync.InspectRetryCache"),
        TEXT("Inspect the contents of Saved/BackendSyncCache."),
        FConsoleCommandDelegate::CreateUObject(this, &UAshenBackendSyncSubsystem::InspectRetryCache)
    );

    FlushCacheConsoleCommand = MakeUnique<FAutoConsoleCommand>(
        TEXT("AshenBackendSync.FlushRetryCache"),
        TEXT("Delete all cached backend sync retry payloads."),
        FConsoleCommandDelegate::CreateUObject(this, &UAshenBackendSyncSubsystem::FlushRetryCache)
    );

    // Start periodic retry timer with a single-shot schedule.
    ScheduleRetryTimer(BaseRetryIntervalSeconds, false);
}

void UAshenBackendSyncSubsystem::Deinitialize()
{
    if (UGameInstance* GI = GetGameInstance())
    {
        if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
        {
            Kernel->OnStateVectorInvalidated.RemoveAll(this);
        }
    }

    ClearRetryTimer();

    InspectCacheConsoleCommand.Reset();
    FlushCacheConsoleCommand.Reset();

    Super::Deinitialize();
}

bool UAshenBackendSyncSubsystem::IsBackendSyncEnabled() const
{
    return bAutoSyncOnPublish && !BackendEndpoint.IsEmpty();
}

void UAshenBackendSyncSubsystem::ForceSyncCurrentState()
{
    if (UAshenSoulConstellationSubsystem* Kernel = GetGameInstance()->GetSubsystem<UAshenSoulConstellationSubsystem>())
    {
        CreateAndSendRequest(Kernel->GetStateVector(), Kernel->GetDespairLevel());
    }
}

void UAshenBackendSyncSubsystem::HandleStateVectorInvalidated(const FSoulStateVector& NewState)
{
    if (!IsBackendSyncEnabled())
    {
        return;
    }

    float Despair = 0.0f;
    if (UAshenSoulConstellationSubsystem* Kernel = GetGameInstance()->GetSubsystem<UAshenSoulConstellationSubsystem>())
    {
        Despair = Kernel->GetDespairLevel();
    }

    if (!CreateAndSendRequest(NewState, Despair))
    {
        UE_LOG(LogAshenBackendSync, Warning, TEXT("Failed to enqueue backend sync request."));
    }
}

bool UAshenBackendSyncSubsystem::CreateAndSendRequest(const FSoulStateVector& State, float Despair)
{
    if (BackendEndpoint.IsEmpty())
    {
        UE_LOG(LogAshenBackendSync, Verbose, TEXT("Backend endpoint is empty; skipping sync."));
        return false;
    }

    const FString Payload = SerializeStatePayload(State, Despair);
    if (Payload.IsEmpty())
    {
        UE_LOG(LogAshenBackendSync, Warning, TEXT("Failed to serialize state vector payload."));
        return false;
    }

    const FString CachedPath = SavePayloadToRetryCache(Payload, TEXT("state"), 0);
    if (CachedPath.IsEmpty())
    {
        UE_LOG(LogAshenBackendSync, Warning, TEXT("Failed to persist state payload before dispatch."));
    }

    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
    Request->SetURL(BackendEndpoint);
    Request->SetVerb(TEXT("POST"));
    Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

    if (!AuthorizationHeader.IsEmpty())
    {
        Request->SetHeader(TEXT("Authorization"), AuthorizationHeader);
    }

    Request->SetContentAsString(Payload);
    Request->OnProcessRequestComplete().BindLambda([this, Payload, CachedPath](FHttpRequestPtr Req, FHttpResponsePtr Resp, bool bWasSuccessful)
    {
        const bool bSuccess = bWasSuccessful && Resp.IsValid() && Resp->GetResponseCode() >= 200 && Resp->GetResponseCode() < 300;
        if (bSuccess)
        {
            if (!CachedPath.IsEmpty())
            {
                DeleteRetryCacheFile(CachedPath);
            }
            UE_LOG(LogAshenBackendSync, Verbose, TEXT("Backend sync request succeeded."));
            return;
        }

        UE_LOG(LogAshenBackendSync, Warning, TEXT("State sync request failed; payload remains cached for retry."));
        if (CachedPath.IsEmpty())
        {
            const FString RepersistedPath = SavePayloadToRetryCache(Payload, TEXT("state"), 0);
            if (!RepersistedPath.IsEmpty())
            {
                UE_LOG(LogAshenBackendSync, Log, TEXT("Persisted failed state sync payload for retry."));
            }
            else
            {
                UE_LOG(LogAshenBackendSync, Warning, TEXT("Failed to persist failed state sync payload."));
            }
        }
    });

    const bool bDispatched = Request->ProcessRequest();
    if (!bDispatched)
    {
        if (CachedPath.IsEmpty())
        {
            const FString RepersistedPath = SavePayloadToRetryCache(Payload, TEXT("state"), 0);
            if (!RepersistedPath.IsEmpty())
            {
                UE_LOG(LogAshenBackendSync, Log, TEXT("Persisted state payload due to immediate dispatch failure."));
            }
            else
            {
                UE_LOG(LogAshenBackendSync, Warning, TEXT("Failed to persist state payload after immediate dispatch failure."));
            }
        }
        UE_LOG(LogAshenBackendSync, Warning, TEXT("Backend sync request failed to dispatch."));
    }
    else
    {
        UE_LOG(LogAshenBackendSync, Verbose, TEXT("Backend sync request dispatched to %s."), *BackendEndpoint);
    }

    return bDispatched;
}

FString UAshenBackendSyncSubsystem::SerializeStatePayload(const FSoulStateVector& State, float Despair) const
{
    TSharedRef<FJsonObject> JsonObject = MakeShared<FJsonObject>();
    if (!FJsonObjectConverter::UStructToJsonObject(FSoulStateVector::StaticStruct(), &State, JsonObject, 0, 0))
    {
        return FString();
    }

    JsonObject->SetNumberField(TEXT("Despair"), Despair);
    JsonObject->SetStringField(TEXT("Timestamp"), FDateTime::UtcNow().ToIso8601());

    FString JsonString;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
    if (!FJsonSerializer::Serialize(JsonObject, Writer))
    {
        return FString();
    }

    return JsonString;
}

FString UAshenBackendSyncSubsystem::SavePayloadToRetryCache(const FString& Payload, const FString& PayloadType, int32 Attempts)
{
    TSharedRef<FJsonObject> RetryObject = MakeShared<FJsonObject>();
    RetryObject->SetStringField(TEXT("PayloadType"), PayloadType);
    RetryObject->SetNumberField(TEXT("Attempts"), Attempts);
    RetryObject->SetStringField(TEXT("Timestamp"), FDateTime::UtcNow().ToIso8601());
    RetryObject->SetStringField(TEXT("Payload"), Payload);

    FString JsonString;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
    if (!FJsonSerializer::Serialize(RetryObject, Writer))
    {
        return FString();
    }

    const FString FileName = GenerateRetryCacheFileName();
    const FString FullPath = FPaths::Combine(RetryCacheDir, FileName);
    return FFileHelper::SaveStringToFile(JsonString, *FullPath) ? FullPath : FString();
}

FString UAshenBackendSyncSubsystem::GenerateRetryCacheFileName() const
{
    return FString::Printf(TEXT("retry_%s.json"), *FGuid::NewGuid().ToString(EGuidFormats::Digits));
}

bool UAshenBackendSyncSubsystem::DeleteRetryCacheFile(const FString& FullPath) const
{
    IPlatformFile& PF = FPlatformFileManager::Get().GetPlatformFile();
    return PF.DeleteFile(*FullPath);
}

bool UAshenBackendSyncSubsystem::ShouldRetryPayload(const TSharedPtr<FJsonObject>& RetryObject) const
{
    if (!RetryObject.IsValid())
    {
        return false;
    }

    int32 Attempts = 0;
    RetryObject->TryGetNumberField(TEXT("Attempts"), Attempts);
    return Attempts < MaxRetryAttempts;
}

void UAshenBackendSyncSubsystem::ScheduleRetryTimer(float DelaySeconds, bool bLoop)
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(RetryTimerHandle);
        World->GetTimerManager().SetTimer(RetryTimerHandle, [this]() { ProcessRetryCache(); }, DelaySeconds, bLoop);
    }
}

void UAshenBackendSyncSubsystem::ClearRetryTimer()
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(RetryTimerHandle);
    }
}

void UAshenBackendSyncSubsystem::InspectRetryCache() const
{
    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
    if (!PlatformFile.DirectoryExists(*RetryCacheDir))
    {
        UE_LOG(LogAshenBackendSync, Log, TEXT("Retry cache directory does not exist: %s"), *RetryCacheDir);
        return;
    }

    TArray<FString> Files;
    PlatformFile.FindFiles(Files, *RetryCacheDir, TEXT(".json"));
    UE_LOG(LogAshenBackendSync, Log, TEXT("Retry cache contains %d files."), Files.Num());

    for (const FString& FileName : Files)
    {
        const FString FullPath = FPaths::Combine(RetryCacheDir, FileName);
        FString FileContents;
        if (!FFileHelper::LoadFileToString(FileContents, *FullPath))
        {
            UE_LOG(LogAshenBackendSync, Warning, TEXT("Unable to read retry cache file: %s"), *FullPath);
            continue;
        }

        TSharedPtr<FJsonObject> RetryObject;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(FileContents);
        if (!FJsonSerializer::Deserialize(Reader, RetryObject) || !RetryObject.IsValid())
        {
            UE_LOG(LogAshenBackendSync, Warning, TEXT("Invalid retry cache JSON: %s"), *FullPath);
            continue;
        }

        const FString PayloadType = RetryObject->GetStringField(TEXT("PayloadType"));
        const int32 Attempts = static_cast<int32>(RetryObject->GetNumberField(TEXT("Attempts")));
        const FString Timestamp = RetryObject->GetStringField(TEXT("Timestamp"));
        UE_LOG(LogAshenBackendSync, Log, TEXT("Cache item: %s, type=%s, attempts=%d, timestamp=%s"), *FileName, *PayloadType, Attempts, *Timestamp);
    }
}

void UAshenBackendSyncSubsystem::FlushRetryCache()
{
    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
    if (!PlatformFile.DirectoryExists(*RetryCacheDir))
    {
        UE_LOG(LogAshenBackendSync, Log, TEXT("Retry cache directory does not exist: %s"), *RetryCacheDir);
        return;
    }

    TArray<FString> Files;
    PlatformFile.FindFiles(Files, *RetryCacheDir, TEXT(".json"));
    int32 DeletedCount = 0;
    for (const FString& FileName : Files)
    {
        const FString FullPath = FPaths::Combine(RetryCacheDir, FileName);
        if (PlatformFile.DeleteFile(*FullPath))
        {
            DeletedCount++;
        }
        else
        {
            UE_LOG(LogAshenBackendSync, Warning, TEXT("Failed to delete retry cache file: %s"), *FullPath);
        }
    }

    UE_LOG(LogAshenBackendSync, Log, TEXT("Flushed %d retry cache files."), DeletedCount);
}

void UAshenBackendSyncSubsystem::ProcessRetryCache()
{
    if (BackendEndpoint.IsEmpty())
    {
        ScheduleRetryTimer(BaseRetryIntervalSeconds, false);
        return;
    }

    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
    TArray<FString> Files;
    PlatformFile.FindFiles(Files, *RetryCacheDir, TEXT(".json"));
    if (Files.Num() == 0)
    {
        ScheduleRetryTimer(BaseRetryIntervalSeconds, false);
        return;
    }

    for (const FString& FileName : Files)
    {
        const FString FullPath = FPaths::Combine(RetryCacheDir, FileName);
        FString FileContents;
        if (!FFileHelper::LoadFileToString(FileContents, *FullPath))
        {
            UE_LOG(LogAshenBackendSync, Warning, TEXT("Unable to read retry cache file: %s"), *FullPath);
            continue;
        }

        TSharedPtr<FJsonObject> RetryObject;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(FileContents);
        if (!FJsonSerializer::Deserialize(Reader, RetryObject) || !RetryObject.IsValid())
        {
            UE_LOG(LogAshenBackendSync, Warning, TEXT("Invalid retry payload JSON: %s"), *FullPath);
            DeleteRetryCacheFile(FullPath);
            continue;
        }

        if (!ShouldRetryPayload(RetryObject))
        {
            UE_LOG(LogAshenBackendSync, Warning, TEXT("Dropping retry payload after %d attempts: %s"), static_cast<int32>(RetryObject->GetNumberField(TEXT("Attempts"))), *FullPath);
            DeleteRetryCacheFile(FullPath);
            continue;
        }

        const FString Payload = RetryObject->GetStringField(TEXT("Payload"));
        if (Payload.IsEmpty())
        {
            UE_LOG(LogAshenBackendSync, Warning, TEXT("Retry payload missing content: %s"), *FullPath);
            DeleteRetryCacheFile(FullPath);
            continue;
        }

        TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
        Request->SetURL(BackendEndpoint);
        Request->SetVerb(TEXT("POST"));
        Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
        if (!AuthorizationHeader.IsEmpty())
        {
            Request->SetHeader(TEXT("Authorization"), AuthorizationHeader);
        }
        Request->SetContentAsString(Payload);

        Request->OnProcessRequestComplete().BindLambda([this, FullPath, RetryObject](FHttpRequestPtr Req, FHttpResponsePtr Resp, bool bOk)
        {
            const bool bSuccess = bOk && Resp.IsValid() && Resp->GetResponseCode() >= 200 && Resp->GetResponseCode() < 300;
            if (bSuccess)
            {
                UE_LOG(LogAshenBackendSync, Log, TEXT("Retry cache payload succeeded: %s"), *FullPath);
                DeleteRetryCacheFile(FullPath);
                return;
            }

            int32 Attempts = 0;
            RetryObject->TryGetNumberField(TEXT("Attempts"), Attempts);
            Attempts++;
            RetryObject->SetNumberField(TEXT("Attempts"), Attempts);
            FString UpdatedJson;
            TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&UpdatedJson);
            if (FJsonSerializer::Serialize(RetryObject.ToSharedRef(), Writer))
            {
                FFileHelper::SaveStringToFile(UpdatedJson, *FullPath);
            }

            const float BackoffSeconds = FMath::Pow(RetryBackoffMultiplier, Attempts - 1) * BaseRetryIntervalSeconds;
            UE_LOG(LogAshenBackendSync, Warning, TEXT("Retry cache payload failed (%d). Next backoff: %.1fs. File: %s"), Attempts, BackoffSeconds, *FullPath);
            ScheduleRetryTimer(BackoffSeconds, false);
        });

        if (!Request->ProcessRequest())
        {
            UE_LOG(LogAshenBackendSync, Warning, TEXT("Failed to dispatch retry cache request: %s"), *FullPath);
            ScheduleRetryTimer(BaseRetryIntervalSeconds, false);
        }
    }
}

void UAshenBackendSyncSubsystem::OnSyncResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    if (!bWasSuccessful || !Response.IsValid())
    {
        UE_LOG(LogAshenBackendSync, Warning, TEXT("Backend sync request failed. Success=%d, ResponseValid=%d"), bWasSuccessful, Response.IsValid());
        if (Response.IsValid())
        {
            UE_LOG(LogAshenBackendSync, Warning, TEXT("Status=%d, Body=%s"), Response->GetResponseCode(), *Response->GetContentAsString());
        }
        return;
    }

    const int32 StatusCode = Response->GetResponseCode();
    const FString ResponseBody = Response->GetContentAsString();

    if (StatusCode >= 200 && StatusCode < 300)
    {
        UE_LOG(LogAshenBackendSync, Log, TEXT("Backend sync succeeded (%d)."), StatusCode);
    }
    else
    {
        UE_LOG(LogAshenBackendSync, Warning, TEXT("Backend sync returned non-success status %d: %s"), StatusCode, *ResponseBody);
    }
}

void UAshenBackendSyncSubsystem::EmitImprintsAsync(const TArray<FPsychologicalImprint>& Imprints)
{
    if (BackendEndpoint.IsEmpty()) return;

    // Convert imprints array to JSON
    TSharedRef<FJsonObject> RootObj = MakeShared<FJsonObject>();
    TArray<TSharedPtr<FJsonValue>> JsonArray;
    for (const FPsychologicalImprint& I : Imprints)
    {
        TSharedRef<FJsonObject> J = MakeShared<FJsonObject>();
        J->SetStringField(TEXT("Type"), StaticEnum<EImprintType>()->GetNameStringByValue(static_cast<int64>(I.Type)));
        J->SetNumberField(TEXT("Weight"), I.Weight);
        J->SetNumberField(TEXT("Timestamp"), I.Timestamp);
        JsonArray.Add(MakeShared<FJsonValueObject>(J));
    }
    RootObj->SetArrayField(TEXT("Imprints"), JsonArray);
    RootObj->SetStringField(TEXT("Timestamp"), FDateTime::UtcNow().ToIso8601());

    FString OutString;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutString);
    if (!FJsonSerializer::Serialize(RootObj, Writer))
    {
        UE_LOG(LogAshenBackendSync, Warning, TEXT("Failed to serialize imprints JSON."));
        return;
    }

    // Dispatch request asynchronously; if dispatch fails or response is non-success, keep the cached payload for retry.
    const FString CachedPath = SavePayloadToRetryCache(OutString, TEXT("imprint"), 0);

    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
    Request->SetURL(BackendEndpoint);
    Request->SetVerb(TEXT("POST"));
    Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    if (!AuthorizationHeader.IsEmpty()) Request->SetHeader(TEXT("Authorization"), AuthorizationHeader);
    Request->SetContentAsString(OutString);

    Request->OnProcessRequestComplete().BindLambda([this, CachedPath](FHttpRequestPtr Req, FHttpResponsePtr Resp, bool bOk)
    {
        const bool bSuccess = bOk && Resp.IsValid() && Resp->GetResponseCode() >= 200 && Resp->GetResponseCode() < 300;
        if (bSuccess)
        {
            if (!CachedPath.IsEmpty())
            {
                DeleteRetryCacheFile(CachedPath);
            }
            return;
        }

        UE_LOG(LogAshenBackendSync, Warning, TEXT("Imprint payload failed; leaving cache item for retry."));
    });

    if (!Request->ProcessRequest())
    {
        if (CachedPath.IsEmpty())
        {
            const FString RetryPath = SavePayloadToRetryCache(OutString, TEXT("imprint"), 0);
            if (RetryPath.IsEmpty())
            {
                UE_LOG(LogAshenBackendSync, Warning, TEXT("Failed to persist imprint payload after immediate dispatch failure."));
            }
            else
            {
                UE_LOG(LogAshenBackendSync, Log, TEXT("Persisted imprint payload due to immediate dispatch failure."));
            }
        }
        else
        {
            UE_LOG(LogAshenBackendSync, Log, TEXT("Persisted imprint payload due to immediate dispatch failure."));
        }
    }
}
