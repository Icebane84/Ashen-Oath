// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenPoiseHitstopCameraShakeAdapter.h"

UAshenPoiseHitstopCameraShakeAdapter::UAshenPoiseHitstopCameraShakeAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenPoiseHitstopCameraShakeAdapter::EvaluateCombatCameraTrauma(
	EPoiseStaggerState StaggerState,
	EAshenWeightClass WeightClass,
	bool bDidDodge) const
{
	if (StaggerState == EPoiseStaggerState::PoiseBroken)
	{
		return 0.40f; // Heavy camera punch on poise break
	}

	if (bDidDodge && (WeightClass == EAshenWeightClass::HeavyLoad || WeightClass == EAshenWeightClass::Overburdened))
	{
		return 0.25f; // Heavy body slam screen shake
	}

	return 0.0f;
}
