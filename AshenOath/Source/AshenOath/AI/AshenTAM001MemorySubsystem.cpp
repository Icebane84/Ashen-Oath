// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenTAM001MemorySubsystem.h"

void UAshenTAM001MemorySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveWeights.RecencyWeight = 1.0f;
	ActiveWeights.ConsistencyScore = 0.5f;
	ActiveWeights.SeverityImpact = 0.0f;
	ActiveWeights.bIsSymbioticResonanceUnlocked = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenTAM001MemorySubsystem: TAM-001 Memory Model Subsystem initialized."));
}
void UAshenTAM001MemorySubsystem::Deinitialize() { Super::Deinitialize(); }

void UAshenTAM001MemorySubsystem::RecordCooperativeAction(bool bSuccessfulCoordination, float FailureSeverity)
{
	if (bSuccessfulCoordination)
	{
		ActiveWeights.ConsistencyScore = FMath::Clamp(ActiveWeights.ConsistencyScore + 0.10f, 0.0f, 1.0f);
		ActiveWeights.SeverityImpact = FMath::Clamp(ActiveWeights.SeverityImpact - 0.05f, 0.0f, 1.0f);
	}
	else
	{
		ActiveWeights.ConsistencyScore = FMath::Clamp(ActiveWeights.ConsistencyScore - 0.15f, 0.0f, 1.0f);
		ActiveWeights.SeverityImpact = FMath::Clamp(ActiveWeights.SeverityImpact + FailureSeverity, 0.0f, 1.0f);
	}

	ActiveWeights.bIsSymbioticResonanceUnlocked = EvaluateSymbioticResonance();
	UE_LOG(LogTemp, Warning, TEXT("UAshenTAM001MemorySubsystem: TAM-001 Update -> Consistency: %.2f | Severity: %.2f | Resonance: %s"),
		ActiveWeights.ConsistencyScore, ActiveWeights.SeverityImpact, ActiveWeights.bIsSymbioticResonanceUnlocked ? TEXT("UNLOCKED") : TEXT("LOCKED"));
}

bool UAshenTAM001MemorySubsystem::EvaluateSymbioticResonance() const
{
	// High trust threshold: Consistency >= 0.80 and Severity <= 0.20
	return (ActiveWeights.ConsistencyScore >= 0.80f && ActiveWeights.SeverityImpact <= 0.20f);
}
