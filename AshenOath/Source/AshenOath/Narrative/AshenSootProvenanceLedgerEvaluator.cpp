// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenSootProvenanceLedgerEvaluator.h"

UAshenSootProvenanceLedgerEvaluator::UAshenSootProvenanceLedgerEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenSootProvenanceLedgerEvaluator::CalculateTotalCampaignSoot(const TArray<float>& ScenarioSootMicrons) const
{
	float Total = 0.0f;
	for (float Microns : ScenarioSootMicrons)
	{
		Total += FMath::Max(0.0f, Microns);
	}
	return Total;
}

float UAshenSootProvenanceLedgerEvaluator::EvaluateWeaponLuster(float CurrentSootMicrons, float MaxSootMicrons) const
{
	if (MaxSootMicrons <= 0.0f)
	{
		return 1.0f;
	}

	const float Ratio = FMath::Clamp(CurrentSootMicrons / MaxSootMicrons, 0.0f, 1.0f);
	return 1.0f - Ratio;
}
