// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenAlchemicalSlagConvergenceSubsystem.h"

UAshenAlchemicalSlagConvergenceSubsystem::UAshenAlchemicalSlagConvergenceSubsystem()
{
	BladeVector.SootLevel = 0.0f;
	BladeVector.SurfaceState = EOathbringerBladeSurfaceState::PolishedResolve;
	BladeVector.ActiveCoating = EAlchemicalBladeCoating::None;
	BladeVector.RemainingCoatingCharges = 0;
}

void UAshenAlchemicalSlagConvergenceSubsystem::AddSoot(float DeltaSoot)
{
	BladeVector.SootLevel = FMath::Clamp(BladeVector.SootLevel + DeltaSoot, 0.0f, 1.0f);
	UpdateSurfaceState();
	OnBladeSootLevelChanged.Broadcast(BladeVector.SootLevel, BladeVector.SurfaceState);
}

void UAshenAlchemicalSlagConvergenceSubsystem::ApplyCoating(
	EAlchemicalBladeCoating NewCoating,
	int32 Charges)
{
	BladeVector.ActiveCoating = NewCoating;
	BladeVector.RemainingCoatingCharges = Charges;
	OnAlchemicalCoatingApplied.Broadcast(NewCoating, Charges);
}

void UAshenAlchemicalSlagConvergenceSubsystem::PolishBladeAtCampfire()
{
	BladeVector.SootLevel = 0.0f;
	UpdateSurfaceState();
	OnBladeSootLevelChanged.Broadcast(BladeVector.SootLevel, BladeVector.SurfaceState);
	OnBladePolishedAtCampfire.Broadcast(300.0f); // 5 minute Resolve Buff
}

FThermalReactionResult UAshenAlchemicalSlagConvergenceSubsystem::ProcessHitReaction(
	bool bTargetIsChilled,
	bool bTargetInAcidRain,
	bool bTargetInLightningStorm)
{
	FThermalReactionResult Result;
	Result.ReactionType = EThermalReactionType::None;
	Result.BonusDamage = 0.0f;
	Result.AoERadiusUU = 0.0f;
	Result.PoiseDamageMultiplier = 1.0f;

	const bool bIsSuperheated = (BladeVector.SurfaceState == EOathbringerBladeSurfaceState::SuperheatedThermalSlag);

	// 1. Conflagration Deflagration: Superheated Slag + Pyrophoric Naphtha
	if (bIsSuperheated && BladeVector.ActiveCoating == EAlchemicalBladeCoating::PyrophoricNaphtha)
	{
		Result.ReactionType = EThermalReactionType::ConflagrationDeflagration;
		Result.BonusDamage = 450.0f;
		Result.AoERadiusUU = 400.0f;
		Result.PoiseDamageMultiplier = 1.50f;

		// Consumes all soot
		BladeVector.SootLevel = 0.0f;
		UpdateSurfaceState();
	}
	// 2. Thermal Shock Shatter: Superheated Slag + Chilled Target
	else if (bIsSuperheated && (bTargetIsChilled || BladeVector.ActiveCoating == EAlchemicalBladeCoating::GlacialFrostResin))
	{
		Result.ReactionType = EThermalReactionType::ThermalShockShatter;
		Result.BonusDamage = 250.0f;
		Result.AoERadiusUU = 0.0f;
		Result.PoiseDamageMultiplier = 2.00f; // +100% Poise Shatter
	}
	// 3. Galvanic Shock Burst: Conductive Copper Salve + Lightning Storm
	else if (BladeVector.ActiveCoating == EAlchemicalBladeCoating::ConductiveCopperSalve && bTargetInLightningStorm)
	{
		Result.ReactionType = EThermalReactionType::GalvanicShockBurst;
		Result.BonusDamage = 500.0f;
		Result.AoERadiusUU = 500.0f;
		Result.PoiseDamageMultiplier = 1.30f;
	}
	// 4. Acidic Vapor Cloud: Vitriol Acid + Superheated Slag
	else if (bIsSuperheated && (BladeVector.ActiveCoating == EAlchemicalBladeCoating::VitriolAcid || bTargetInAcidRain))
	{
		Result.ReactionType = EThermalReactionType::AcidicVaporCloud;
		Result.BonusDamage = 150.0f;
		Result.AoERadiusUU = 300.0f;
		Result.PoiseDamageMultiplier = 1.20f;
	}

	// Consume coating charge on hit
	if (BladeVector.RemainingCoatingCharges > 0)
	{
		BladeVector.RemainingCoatingCharges--;
		if (BladeVector.RemainingCoatingCharges == 0)
		{
			BladeVector.ActiveCoating = EAlchemicalBladeCoating::None;
		}
	}

	if (Result.ReactionType != EThermalReactionType::None)
	{
		OnThermalReactionTriggered.Broadcast(Result.ReactionType, Result);
	}

	return Result;
}

void UAshenAlchemicalSlagConvergenceSubsystem::UpdateSurfaceState()
{
	if (BladeVector.SootLevel >= 0.80f)
	{
		BladeVector.SurfaceState = EOathbringerBladeSurfaceState::SuperheatedThermalSlag;
	}
	else if (BladeVector.SootLevel > 0.20f)
	{
		BladeVector.SurfaceState = EOathbringerBladeSurfaceState::AccumulatingSoot;
	}
	else
	{
		BladeVector.SurfaceState = EOathbringerBladeSurfaceState::PolishedResolve;
	}
}
