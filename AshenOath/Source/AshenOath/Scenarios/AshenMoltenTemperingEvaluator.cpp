// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenMoltenTemperingEvaluator.h"

UAshenMoltenTemperingEvaluator::UAshenMoltenTemperingEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenMoltenTemperingEvaluator::EvaluateFireDamageBonus(float BladeTempC) const
{
	if (BladeTempC <= 100.0f)
	{
		return 0.0f;
	}

	// 100C to 800C scales 0.0 to 0.40 fire damage bonus
	const float Alpha = FMath::Clamp((BladeTempC - 100.0f) / 700.0f, 0.0f, 1.0f);
	return Alpha * 0.40f;
}

ETemperedBladeState UAshenMoltenTemperingEvaluator::ClassifyBladeState(float BladeTempC) const
{
	if (BladeTempC >= 900.0f)
	{
		return ETemperedBladeState::Overheated;
	}
	else if (BladeTempC >= 400.0f)
	{
		return ETemperedBladeState::MoltenHeated;
	}

	return ETemperedBladeState::ColdSteel;
}
