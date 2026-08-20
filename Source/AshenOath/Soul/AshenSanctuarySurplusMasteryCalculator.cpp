// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 669: Ashen Sanctuary Surplus Mastery Calculator

#include "AshenSanctuarySurplusMasteryCalculator.h"

void UAshenSanctuarySurplusMasteryCalculator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveSavedResources = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenSanctuarySurplusMasteryCalculator: Initialized — Sanctuary Surplus Mastery Calculator ONLINE."));
}

int32 UAshenSanctuarySurplusMasteryCalculator::CalculateSanctuarySurplus(float CurrentStainPercent, int32 TotalQuestsCompleted)
{
	const float RetainedRatio = 1.0f - (CurrentStainPercent / 100.0f);
	ActiveSavedResources = FMath::TruncToInt(TotalQuestsCompleted * 50.0f * RetainedRatio);
	const float TuningMult = 1.0f + (ActiveSavedResources / 500.0f);

	OnSurplusCalculated.Broadcast(ActiveSavedResources, TuningMult);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSanctuarySurplusMasteryCalculator: SANCTUARY SURPLUS CALCULATED -> Saved Resources: %d | Resonance Tuning Mult: %.2fx."),
		ActiveSavedResources, TuningMult);

	return ActiveSavedResources;
}
