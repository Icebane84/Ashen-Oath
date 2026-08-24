// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenParasiticBladePostProcessAdapter.h"

UAshenParasiticBladePostProcessAdapter::UAshenParasiticBladePostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenParasiticBladePostProcessAdapter::EvaluateVeinVignetteIntensity(float Corruption01) const
{
	return FMath::Clamp(Corruption01 * 0.85f, 0.0f, 0.85f);
}

float UAshenParasiticBladePostProcessAdapter::EvaluateFrostChillFilterIntensity(bool bIsFrozen) const
{
	return bIsFrozen ? 0.70f : 0.0f;
}
