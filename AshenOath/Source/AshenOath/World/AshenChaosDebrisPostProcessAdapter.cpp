// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenChaosDebrisPostProcessAdapter.h"

UAshenChaosDebrisPostProcessAdapter::UAshenChaosDebrisPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenChaosDebrisPostProcessAdapter::EvaluateCollapseCameraShake(float ImpactJoules) const
{
	return FMath::Clamp(ImpactJoules / 4000.0f, 0.0f, 2.0f);
}

float UAshenChaosDebrisPostProcessAdapter::EvaluateDustParticleDensity(float DebrisMassKg) const
{
	return FMath::Clamp(DebrisMassKg / 200.0f, 0.0f, 1.0f);
}
