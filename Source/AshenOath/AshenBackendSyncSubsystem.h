// Copyright Phoenix Protocol / Ashen Oath. All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenSoulStateVector.h"
#include "AshenOath_ImprintBufferComponent.h"
#include "HAL/PlatformFilemanager.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "HAL/IConsoleManager.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Dom/JsonObject.h"
#include "TimerManager.h"
#include "AshenBackendSyncSubsystem.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAshenBackendSync, Log, All);

UCLASS(Config=Game, DefaultConfig)
class ASHENOATH_API UAshenBackendSyncSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    UFUNCTION(BlueprintCallable, Category = "AshenOath|Backend")
    bool IsBackendSyncEnabled() const;

    UFUNCTION(BlueprintCallable, Category = "AshenOath|Backend")
    void ForceSyncCurrentState();

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Backend")
    bool bAutoSyncOnPublish = true;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Backend")
    FString BackendEndpoint;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Backend")
    FString AuthorizationHeader;

    /** Emit raw imprints (session-volatile) to the backend asynchronously. */
    UFUNCTION(BlueprintCallable, Category = "AshenOath|Backend")
    void EmitImprintsAsync(const TArray<FPsychologicalImprint>& Imprints);

    UFUNCTION(Exec, Category = "AshenOath|Backend")
    void InspectRetryCache() const;

    UFUNCTION(Exec, Category = "AshenOath|Backend")
    void FlushRetryCache();

private:
    UFUNCTION()
    void HandleStateVectorInvalidated(const FSoulStateVector& NewState);

    bool CreateAndSendRequest(const FSoulStateVector& State, float Despair);
    FString SerializeStatePayload(const FSoulStateVector& State, float Despair) const;
    void OnSyncResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

    FString SavePayloadToRetryCache(const FString& Payload, const FString& PayloadType, int32 Attempts = 0);
    void ProcessRetryCache();
    void ScheduleRetryTimer(float DelaySeconds, bool bLoop = false);
    void ClearRetryTimer();
    bool ShouldRetryPayload(const TSharedPtr<FJsonObject>& RetryObject) const;
    bool DeleteRetryCacheFile(const FString& FullPath) const;
    FString GenerateRetryCacheFileName() const;

    bool bIsInitialized = false;

    UPROPERTY(Config, EditAnywhere, Category = "AshenOath|Backend")
    int32 MaxRetryAttempts = 5;

    UPROPERTY(Config, EditAnywhere, Category = "AshenOath|Backend")
    float BaseRetryIntervalSeconds = 10.0f;

    UPROPERTY(Config, EditAnywhere, Category = "AshenOath|Backend")
    float RetryBackoffMultiplier = 2.0f;

    // Retry queue directory under Saved/BackendSyncCache
    FString RetryCacheDir;

    // Console commands for cache inspection and flush
    TUniquePtr<FAutoConsoleCommand> InspectCacheConsoleCommand;
    TUniquePtr<FAutoConsoleCommand> FlushCacheConsoleCommand;

    // Timer handle for retrying cached payloads
    FTimerHandle RetryTimerHandle;

    // Interval in seconds between retry attempts
    float RetryIntervalSeconds = 10.0f;
};
