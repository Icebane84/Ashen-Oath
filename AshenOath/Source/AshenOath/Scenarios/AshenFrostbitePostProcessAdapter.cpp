// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenFrostbitePostProcessAdapter.h"

UAshenFrostbitePostProcessAdapter::UAshenFrostbitePostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenFrostbitePostProcessAdapter::EvaluateFrostVignetteIntensity(float FrostbiteGauge) const
{
	return FMath::Clamp(FrostbiteGauge, 0.0f, 1.0f);
}

float UAshenFrostbitePostProcessAdapter::EvaluateColorTemperatureShift(float FrostbiteGauge) const
{
	// Drops camera color temperature by up to -2500K for sub-zero icy feel
	return -FMath::Clamp(FrostbiteGauge, 0.0f, 1.0f) * 2500.0f;
}
