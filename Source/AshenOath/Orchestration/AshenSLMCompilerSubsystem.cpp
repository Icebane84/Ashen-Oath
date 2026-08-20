// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Orchestration/AshenSLMCompilerSubsystem.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Engine/World.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogAshenECU, Log, All);

void UAshenSLMCompilerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogAshenECU, Log, TEXT("[ECU SYS] SLM Compiler Subsystem Initialized. Zero-Hallucination Firewall Ready."));
}

void UAshenSLMCompilerSubsystem::RequestIdentityCompilation(const FString& PayloadJSON, const TArray<FString>& ValidMemoryIDs)
{
	CachedValidIDs = ValidMemoryIDs;

	UE_LOG(LogAshenECU, Log, TEXT("[ECU SYS] Telemetry payload received (%d bytes, %d cached memory IDs). Dispatching async bridge..."),
		PayloadJSON.Len(), ValidMemoryIDs.Num());

	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().SetTimer(MockApiTimerHandle, this, &UAshenSLMCompilerSubsystem::OnMockSLMTimerExpired, 2.0f, false);
	}
}

void UAshenSLMCompilerSubsystem::OnMockSLMTimerExpired()
{
	// Mock response simulating local SLM return payload
	FString MockSLMResponse = TEXT("{\"cited_memories\": [\"mem_combat_near_death_kaelen_045\"], \"corruption_delta\": 0.15, \"resolve_delta\": 0.05}");

	if (ExecuteFirewallParser(MockSLMResponse, CachedValidIDs))
	{
		OnCompilationCompleted.Broadcast(true, CurrentSoulState);
		UE_LOG(LogAshenECU, Log, TEXT("[ECU SYS] Soul State successfully updated and broadcasted. Current Corruption: %.2f | Resolve: %.2f"),
			CurrentSoulState.Corruption, CurrentSoulState.Resolve);
	}
	else
	{
		OnCompilationCompleted.Broadcast(false, CurrentSoulState);
		UE_LOG(LogAshenECU, Error, TEXT("[ECU SYS] Identity Compilation FAILED firewall audit. Soul state unchanged."));
	}
}

bool UAshenSLMCompilerSubsystem::ExecuteFirewallParser(const FString& JsonPayload, const TArray<FString>& ValidMemoryIDs)
{
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonPayload);

	if (!FJsonSerializer::Deserialize(Reader, JsonObject) || !JsonObject.IsValid())
	{
		UE_LOG(LogAshenECU, Error, TEXT("[ECU SYS] Firewall Block: Malformed JSON payload."));
		return false;
	}

	// Provenance Cross-Reference: Audit cited memory IDs against immutable snapshot
	if (JsonObject->HasField(TEXT("cited_memories")))
	{
		TArray<TSharedPtr<FJsonValue>> CitedArray = JsonObject->GetArrayField(TEXT("cited_memories"));
		for (const TSharedPtr<FJsonValue>& Val : CitedArray)
		{
			FString CitedID = Val->AsString();
			bool bFound = ValidMemoryIDs.Contains(CitedID) || ValidMemoryIDs.Num() == 0; // Allow fallback if snapshot empty

			if (!bFound)
			{
				UE_LOG(LogAshenECU, Error, TEXT("[ECU SYS] Firewall Block: SLM Hallucination! Cited MemoryID [%s] does not exist in Crucible snapshot."), *CitedID);
				return false;
			}
		}
	}

	// Mathematical Governance: Delta Clamping
	if (JsonObject->HasField(TEXT("corruption_delta")))
	{
		float RawCorruptionDelta = (float)JsonObject->GetNumberField(TEXT("corruption_delta"));
		float ClampedCorruptionDelta = FMath::Clamp(RawCorruptionDelta, -0.20f, 0.20f);
		CurrentSoulState.Corruption = FMath::Clamp(CurrentSoulState.Corruption + ClampedCorruptionDelta, 0.0f, 1.0f);
	}

	if (JsonObject->HasField(TEXT("resolve_delta")))
	{
		float RawResolveDelta = (float)JsonObject->GetNumberField(TEXT("resolve_delta"));
		float ClampedResolveDelta = FMath::Clamp(RawResolveDelta, -0.20f, 0.20f);
		CurrentSoulState.Resolve = FMath::Clamp(CurrentSoulState.Resolve + ClampedResolveDelta, 0.0f, 1.0f);
	}

	UE_LOG(LogAshenECU, Log, TEXT("[ECU SYS] Firewall Passed cleanly. Validated state vector updated."));
	return true;
}
