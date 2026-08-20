#include "Misc/AutomationTest.h"
#include "AshenOath_ImprintBufferComponent.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonWriter.h"
#include "Serialization/JsonSerializer.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFilemanager.h"
#include "HAL/FileManager.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBackendSyncImprintSerializationTest, "AshenOath.Backend.ImprintSerialization", EAutomationTestFlags::ProductFilter | EAutomationTestFlags_ApplicationContextMask)

bool FBackendSyncImprintSerializationTest::RunTest(const FString& Parameters)
{
    FPsychologicalImprint I;
    I.Type = EImprintType::Memory;
    I.Weight = 0.42f;
    I.Timestamp = 1234.5f;

    TSharedRef<FJsonObject> J = MakeShared<FJsonObject>();
    J->SetStringField(TEXT("Type"), StaticEnum<EImprintType>()->GetNameStringByValue(static_cast<int64>(I.Type)));
    J->SetNumberField(TEXT("Weight"), I.Weight);
    J->SetNumberField(TEXT("Timestamp"), I.Timestamp);

    FString Out;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&Out);
    const bool b = FJsonSerializer::Serialize(J, Writer);

    TestTrue(TEXT("Imprint serialized to JSON"), b);
    TestTrue(TEXT("JSON contains Type"), Out.Contains(TEXT("Type")));
    TestTrue(TEXT("JSON contains Weight"), Out.Contains(TEXT("Weight")));

    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBackendSyncRetryPayloadSerializationTest, "AshenOath.Backend.RetryPayloadSerialization", EAutomationTestFlags::ProductFilter | EAutomationTestFlags_ApplicationContextMask)

bool FBackendSyncRetryPayloadSerializationTest::RunTest(const FString& Parameters)
{
    const FString Payload = TEXT("{\"success\":true}");

    TSharedRef<FJsonObject> RetryObject = MakeShared<FJsonObject>();
    RetryObject->SetStringField(TEXT("PayloadType"), TEXT("state"));
    RetryObject->SetNumberField(TEXT("Attempts"), 0);
    RetryObject->SetStringField(TEXT("Payload"), Payload);

    FString Serialized;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&Serialized);
    const bool bSerialized = FJsonSerializer::Serialize(RetryObject, Writer);
    TestTrue(TEXT("Retry payload serialized to JSON"), bSerialized);
    TestTrue(TEXT("Retry JSON contains PayloadType"), Serialized.Contains(TEXT("PayloadType")));
    TestTrue(TEXT("Retry JSON contains Attempts"), Serialized.Contains(TEXT("Attempts")));
    TestTrue(TEXT("Retry JSON contains Payload"), Serialized.Contains(TEXT("Payload")));
    TestTrue(TEXT("Retry JSON contains embedded payload"), Serialized.Contains(TEXT("success")));

    TSharedPtr<FJsonObject> ParsedObject;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Serialized);
    const bool bParsed = FJsonSerializer::Deserialize(Reader, ParsedObject) && ParsedObject.IsValid();
    TestTrue(TEXT("Retry payload JSON deserializes"), bParsed);
    if (bParsed)
    {
        TestEqual(TEXT("PayloadType preserved"), ParsedObject->GetStringField(TEXT("PayloadType")), FString(TEXT("state")));
        TestEqual(TEXT("Attempts preserved"), static_cast<int32>(ParsedObject->GetNumberField(TEXT("Attempts"))), 0);
        TestEqual(TEXT("Payload preserved"), ParsedObject->GetStringField(TEXT("Payload")), Payload);
    }

    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBackendSyncRetryCacheFileIOTest, "AshenOath.Backend.RetryCacheFileIO", EAutomationTestFlags::ProductFilter | EAutomationTestFlags_ApplicationContextMask)

bool FBackendSyncRetryCacheFileIOTest::RunTest(const FString& Parameters)
{
    const FString RetryDir = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("BackendSyncCache"), TEXT("AutomationTest"));
    IFileManager::Get().MakeDirectory(*RetryDir, true);

    const FString TestFilePath = FPaths::Combine(RetryDir, TEXT("retry_test.json"));
    const FString Payload = TEXT("{\"PayloadType\":\"state\",\"Attempts\":0,\"Payload\":\"{}\"}");

    TestTrue(TEXT("Retry cache test file saved"), FFileHelper::SaveStringToFile(Payload, *TestFilePath));
    TestTrue(TEXT("Retry cache test file exists"), FPaths::FileExists(TestFilePath));

    FString Loaded;
    TestTrue(TEXT("Retry cache test file loaded"), FFileHelper::LoadFileToString(Loaded, *TestFilePath));
    TestEqual(TEXT("Retry cache file content preserved"), Loaded, Payload);

    TestTrue(TEXT("Retry cache test file deleted"), IFileManager::Get().Delete(*TestFilePath));
    TestFalse(TEXT("Retry cache test file no longer exists"), FPaths::FileExists(TestFilePath));

    IFileManager::Get().DeleteDirectory(*RetryDir);
    return true;
}
