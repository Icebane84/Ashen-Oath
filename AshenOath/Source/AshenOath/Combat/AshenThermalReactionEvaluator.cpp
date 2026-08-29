// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenThermalReactionEvaluator.h"

UAshenThermalReactionEvaluator::UAshenThermalReactionEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FThermalReactionResult UAshenThermalReactionEvaluator::EvaluateReaction(
	EOathbringerBladeSurfaceState SurfaceState,
	EAlchemicalBladeCoating Coating,
	bool bTargetChilled,
	bool bTargetInAcidRain,
	bool bTargetInLightningStorm) const
{
	FThermalReactionResult Result;
	Result.ReactionType = EThermalReactionType::None;
	Result.BonusDamage = 0.0f;
	Result.AoERadiusUU = 0.0f;
	Result.PoiseDamageMultiplier = 1.0f;

	const bool bIsSuperheated = (SurfaceState == EOathbringerBladeSurfaceState::SuperheatedThermalSlag);

	if (bIsSuperheated && Coating == EAlchemicalBladeCoating::PyrophoricNaphtha)
	{
		Result.ReactionType = EThermalReactionType::ConflagrationDeflagration;
		Result.BonusDamage = 450.0f;
		Result.AoERadiusUU = 400.0f;
		Result.PoiseDamageMultiplier = 1.50f;
	}
	else if (bIsSuperheated && (bTargetChilled || Coating == EAlchemicalBladeCoating::GlacialFrostResin))
	{
		Result.ReactionType = EThermalReactionType::ThermalShockShatter;
		Result.BonusDamage = 250.0f;
		Result.AoERadiusUU = 0.0f;
		Result.PoiseDamageMultiplier = 2.00f; // +100% Poise Shatter
	}
	else if (Coating == EAlchemicalBladeCoating::ConductiveCopperSalve && bTargetInLightningStorm)
	{
		Result.ReactionType = EThermalReactionType::GalvanicShockBurst;
		Result.BonusDamage = 500.0f;
		Result.AoERadiusUU = 500.0f;
		Result.PoiseDamageMultiplier = 1.30f;
	}
	else if (bIsSuperheated && (Coating == EAlchemicalBladeCoating::VitriolAcid || bTargetInAcidRain))
	{
		Result.ReactionType = EThermalReactionType::AcidicVaporCloud;
		Result.BonusDamage = 150.0f;
		Result.AoERadiusUU = 300.0f;
		Result.PoiseDamageMultiplier = 1.20f;
	}

	return Result;
}
