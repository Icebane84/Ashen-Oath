// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenHearthBrazierIgnitionEvaluator.h"

UAshenHearthBrazierIgnitionEvaluator::UAshenHearthBrazierIgnitionEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenHearthBrazierIgnitionEvaluator::EvaluateSanctuaryRadiusUU(float IgnitionProgress) const
{
	const float Clamped = FMath::Clamp(IgnitionProgress, 0.0f, 1.0f);
	return 500.0f + (Clamped * 2000.0f); // 500uu unlit to 2500uu fully sanctified
}
