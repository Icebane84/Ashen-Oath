// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenNightmareCompanionReactionAdapter.h"

UAshenNightmareCompanionReactionAdapter::UAshenNightmareCompanionReactionAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenNightmareCompanionReactionAdapter::BeginPlay() { Super::BeginPlay(); }

FName UAshenNightmareCompanionReactionAdapter::EvaluateDefensiveStance(FName CompanionID, float IncursionIntensity, ETransferenceStrainStage StrainStage)
{
	FName Stance = FName(TEXT("Stance.Default"));
	if (IncursionIntensity >= 0.70f || StrainStage >= ETransferenceStrainStage::Fractured)
	{
		if (CompanionID == FName(TEXT("Garrett")))
		{
			Stance = FName(TEXT("Stance.Garrett.AegisInterception"));
		}
		else if (CompanionID == FName(TEXT("Serafina")))
		{
			Stance = FName(TEXT("Stance.Serafina.SanctuaryFocus"));
		}
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenNightmareCompanionReactionAdapter: Companion %s adopted stance '%s' (Intensity: %.2f, Strain: %d)."),
		*CompanionID.ToString(), *Stance.ToString(), IncursionIntensity, static_cast<int32>(StrainStage));

	return Stance;
}
