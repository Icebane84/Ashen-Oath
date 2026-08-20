// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenSanctuaryHeartstoneCrucibleComponent.h"

UAshenSanctuaryHeartstoneCrucibleComponent::UAshenSanctuaryHeartstoneCrucibleComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenSanctuaryHeartstoneCrucibleComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenSanctuaryHeartstoneCrucibleComponent::CalculateResonanceEfficiency(int32 RemnantsCount) const
{
	const float Efficiency = (float)RemnantsCount * CrucibleResonanceMultiplier;
	UE_LOG(LogTemp, Log, TEXT("UAshenSanctuaryHeartstoneCrucibleComponent: Calculated resonance efficiency for %d remnants: %.2f"),
		RemnantsCount, Efficiency);
	return Efficiency;
}

void UAshenSanctuaryHeartstoneCrucibleComponent::BeginReflectionSession()
{
	bIsReflecting = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenSanctuaryHeartstoneCrucibleComponent: Began soul reflection session at heartstone crucible."));
}

void UAshenSanctuaryHeartstoneCrucibleComponent::EndReflectionSession()
{
	bIsReflecting = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenSanctuaryHeartstoneCrucibleComponent: Ended soul reflection session."));
}

FString UAshenSanctuaryHeartstoneCrucibleComponent::GenerateTelemetryPayload(const FSoulStateVector& InState)
{
	return FString::Printf(TEXT("{\"corruption\": %.2f, \"resolve\": %.2f, \"debt\": %.2f, \"reflecting\": %s}"),
		InState.Corruption, InState.Resolve, InState.IntegrationDebt, bIsReflecting ? TEXT("true") : TEXT("false"));
}

TArray<FString> UAshenSanctuaryHeartstoneCrucibleComponent::GetPendingMemoryIDs() const
{
	TArray<FString> OutIDs;
	OutIDs.Add(TEXT("Mem_001_Greywatch"));
	return OutIDs;
}

void UAshenSanctuaryHeartstoneCrucibleComponent::FlushCompiledMemories()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSanctuaryHeartstoneCrucibleComponent: Flushed compiled memories."));
}
