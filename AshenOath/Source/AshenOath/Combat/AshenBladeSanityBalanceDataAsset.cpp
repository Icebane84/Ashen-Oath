// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenBladeSanityBalanceDataAsset.h"

FBladeHungerCombatBalancing UAshenBladeSanityBalanceDataAsset::GetClampedBladeHunger() const
{
	FBladeHungerCombatBalancing Clamped = BladeHungerParams;
	Clamped.MaxDamageMultiplier = FMath::Clamp(Clamped.MaxDamageMultiplier, 1.0f, 2.5f);
	Clamped.MaxParryWindowPenalty = FMath::Clamp(Clamped.MaxParryWindowPenalty, 0.05f, 0.60f);
	Clamped.MaxDodgeStaminaMultiplier = FMath::Clamp(Clamped.MaxDodgeStaminaMultiplier, 1.0f, 3.0f);
	Clamped.HungerSanityDrainRatePerSecond = FMath::Clamp(Clamped.HungerSanityDrainRatePerSecond, 0.1f, 5.0f);
	return Clamped;
}

FFlowCatharsisBalancing UAshenBladeSanityBalanceDataAsset::GetClampedFlowCatharsis() const
{
	FFlowCatharsisBalancing Clamped = FlowCatharsisParams;
	Clamped.InstantSanityHeal = FMath::Clamp(Clamped.InstantSanityHeal, 10.0f, 100.0f);
	Clamped.FlowDurationSeconds = FMath::Clamp(Clamped.FlowDurationSeconds, 3.0f, 20.0f);
	Clamped.FlowStaminaRegenMultiplier = FMath::Clamp(Clamped.FlowStaminaRegenMultiplier, 1.0f, 4.0f);
	return Clamped;
}

FQuartzConductorBalancing UAshenBladeSanityBalanceDataAsset::GetClampedQuartzConductor() const
{
	FQuartzConductorBalancing Clamped = QuartzConductorParams;
	Clamped.MaxStem02WhisperGain = FMath::Clamp(Clamped.MaxStem02WhisperGain, 0.0f, 1.0f);
	Clamped.MaxMelodicDuckingDb = FMath::Clamp(Clamped.MaxMelodicDuckingDb, -36.0f, 0.0f);
	Clamped.MinLPFCutoffHz = FMath::Clamp(Clamped.MinLPFCutoffHz, 100.0f, 12000.0f);
	Clamped.MaxLPFCutoffHz = FMath::Clamp(Clamped.MaxLPFCutoffHz, 4000.0f, 22000.0f);
	return Clamped;
}
