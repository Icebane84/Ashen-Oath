// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 624: Ashen Entropy Of Meaning Subsystem

#include "AshenEntropyOfMeaningSubsystem.h"

void UAshenEntropyOfMeaningSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveNarrativeEntropy = 0.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenEntropyOfMeaningSubsystem: Initialized — Entropy Of Meaning Subsystem ONLINE."));
}

void UAshenEntropyOfMeaningSubsystem::AccrueNarrativeEntropy(float DeltaEntropy)
{
	ActiveNarrativeEntropy = FMath::Clamp(ActiveNarrativeEntropy + DeltaEntropy, 0.0f, 100.0f);
	const float Velocity = ActiveNarrativeEntropy / 20.0f;

	OnEntropyUpdated.Broadcast(ActiveNarrativeEntropy, Velocity);

	UE_LOG(LogTemp, Warning, TEXT("UAshenEntropyOfMeaningSubsystem: NARRATIVE ENTROPY ACCRUED -> Level: %.1f | Velocity: %.2f."),
		ActiveNarrativeEntropy, Velocity);
}
