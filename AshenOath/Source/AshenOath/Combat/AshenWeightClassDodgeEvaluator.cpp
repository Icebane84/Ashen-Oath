// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenWeightClassDodgeEvaluator.h"

UAshenWeightClassDodgeEvaluator::UAshenWeightClassDodgeEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FDodgeScalingParameters UAshenWeightClassDodgeEvaluator::GetDodgeParametersForWeightClass(
	EAshenWeightClass WeightClass) const
{
	FDodgeScalingParameters Params;

	switch (WeightClass)
	{
	case EAshenWeightClass::LightLoad:
		Params.RollDurationSeconds = 0.32f;
		Params.IFrameDurationSeconds = 0.28f;
		Params.StaminaCost = 15.0f;
		Params.LaunchForce = 1650.0f;
		Params.ImpactCameraTrauma = 0.0f;
		break;

	case EAshenWeightClass::HeavyLoad:
		Params.RollDurationSeconds = 0.55f;
		Params.IFrameDurationSeconds = 0.16f;
		Params.StaminaCost = 35.0f;
		Params.LaunchForce = 1100.0f;
		Params.ImpactCameraTrauma = 0.25f; // Heavy screen thump
		break;

	case EAshenWeightClass::Overburdened:
		Params.RollDurationSeconds = 0.70f;
		Params.IFrameDurationSeconds = 0.05f;
		Params.StaminaCost = 50.0f;
		Params.LaunchForce = 450.0f;
		Params.ImpactCameraTrauma = 0.40f;
		break;

	case EAshenWeightClass::MediumLoad:
	default:
		Params.RollDurationSeconds = 0.40f;
		Params.IFrameDurationSeconds = 0.24f;
		Params.StaminaCost = 20.0f;
		Params.LaunchForce = 1500.0f;
		Params.ImpactCameraTrauma = 0.0f;
		break;
	}

	return Params;
}

EAshenWeightClass UAshenWeightClassDodgeEvaluator::EvaluateWeightClass(
	float WeightKg,
	float MaxLoadKg) const
{
	const float SafeMaxLoad = FMath::Max(1.0f, MaxLoadKg);
	const float Ratio = WeightKg / SafeMaxLoad;

	if (Ratio > 1.0f)
	{
		return EAshenWeightClass::Overburdened;
	}
	if (Ratio > 0.70f)
	{
		return EAshenWeightClass::HeavyLoad;
	}
	if (Ratio <= 0.30f)
	{
		return EAshenWeightClass::LightLoad;
	}
	return EAshenWeightClass::MediumLoad;
}
