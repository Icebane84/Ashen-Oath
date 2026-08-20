// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenCompanionResonanceSyncEvaluator.h"

void UAshenCompanionResonanceSyncEvaluator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionResonanceSyncEvaluator: ResonanceSync Evaluator initialized."));
}

void UAshenCompanionResonanceSyncEvaluator::Deinitialize() { Super::Deinitialize(); }

bool UAshenCompanionResonanceSyncEvaluator::EvaluateResonanceSync(float GarrettTrust, float SerafinaTrust, float GarrettFatigue, float SerafinaFatigue, float ResolveScore)
{
	// ENGINE-SPEC-003 Section III: ResonanceSync criteria
	// |SerafinaTrust - GarrettTrust| < 0.15f AND both Fatigue < 0.4f AND Resolve > 0.5f
	const bool bAligned = FMath::Abs(SerafinaTrust - GarrettTrust) < 0.15f;
	const bool bRested  = (GarrettFatigue < 0.40f) && (SerafinaFatigue < 0.40f);
	const bool bStable  = (ResolveScore > 0.50f);

	const bool bNewState = (bAligned && bRested && bStable);
	if (bNewState != bResonanceSyncActive)
	{
		bResonanceSyncActive = bNewState;
		if (OnResonanceSyncStateChanged.IsBound())
		{
			OnResonanceSyncStateChanged.Broadcast(bResonanceSyncActive);
		}
		UE_LOG(LogTemp, Warning, TEXT("UAshenCompanionResonanceSyncEvaluator: ResonanceSync state changed to %s"),
			bResonanceSyncActive ? TEXT("ACTIVE (15s Damage Bonus & Visual Flourish Granted)") : TEXT("INACTIVE"));
	}
	return bResonanceSyncActive;
}
