// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenBladeSanityConductorConvergenceSubsystem.h"

UAshenBladeSanityConductorConvergenceSubsystem::UAshenBladeSanityConductorConvergenceSubsystem()
{
	CurrentHarmonics.BladeHunger01 = 0.0f;
	CurrentHarmonics.HungerStage = EBladeHungerStage::SatedDormant;
	CurrentHarmonics.CurrentSanity = 100.0f;
	CurrentHarmonics.DissonanceTier = ESanityDissonanceTier::LucidHarmonic;
	CurrentHarmonics.Stem02WhisperGain = 0.0f;
	CurrentHarmonics.MelodicDuckingDb = 0.0f;
	CurrentHarmonics.bFlowStateActive = false;
}

void UAshenBladeSanityConductorConvergenceSubsystem::UpdateConvergenceState(
	float DeltaSeconds,
	float NewHunger01,
	bool bInFlowState)
{
	CurrentHarmonics.BladeHunger01 = FMath::Clamp(NewHunger01, 0.0f, 1.0f);
	CurrentHarmonics.bFlowStateActive = bInFlowState;

	// 1. Resolve Hunger Stage
	if (CurrentHarmonics.BladeHunger01 >= 0.86f)
	{
		CurrentHarmonics.HungerStage = EBladeHungerStage::BloodMadness;
	}
	else if (CurrentHarmonics.BladeHunger01 >= 0.61f)
	{
		CurrentHarmonics.HungerStage = EBladeHungerStage::VoraciousFrenzy;
	}
	else if (CurrentHarmonics.BladeHunger01 >= 0.26f)
	{
		CurrentHarmonics.HungerStage = EBladeHungerStage::AwakenedThirst;
	}
	else
	{
		CurrentHarmonics.HungerStage = EBladeHungerStage::SatedDormant;
	}

	// 2. Sanity Drain Calculation (Hunger drains sanity unless Flow State is active)
	if (bInFlowState)
	{
		// Flow state actively restores sanity (+5.0/s)
		CurrentHarmonics.CurrentSanity = FMath::Clamp(CurrentHarmonics.CurrentSanity + (DeltaSeconds * 5.0f), 0.0f, 100.0f);
	}
	else
	{
		// Sanity decay rate: Hunger * 1.50/s
		const float DrainRate = CurrentHarmonics.BladeHunger01 * 1.50f;
		CurrentHarmonics.CurrentSanity = FMath::Clamp(CurrentHarmonics.CurrentSanity - (DeltaSeconds * DrainRate), 0.0f, 100.0f);
	}

	// 3. Resolve Sanity Dissonance Tier
	if (CurrentHarmonics.CurrentSanity <= 24.0f)
	{
		CurrentHarmonics.DissonanceTier = ESanityDissonanceTier::DeliriumMadness;
	}
	else if (CurrentHarmonics.CurrentSanity <= 49.0f)
	{
		CurrentHarmonics.DissonanceTier = ESanityDissonanceTier::ParanoidStatic;
	}
	else if (CurrentHarmonics.CurrentSanity <= 74.0f)
	{
		CurrentHarmonics.DissonanceTier = ESanityDissonanceTier::AnxiousEchoes;
	}
	else
	{
		CurrentHarmonics.DissonanceTier = ESanityDissonanceTier::LucidHarmonic;
	}

	// 4. Quartz Stem 02 (Whisper) Gain & Melodic Ducking
	if (bInFlowState)
	{
		CurrentHarmonics.Stem02WhisperGain = 0.0f; // Complete silence of dissonance
		CurrentHarmonics.MelodicDuckingDb = 0.0f;
	}
	else
	{
		CurrentHarmonics.Stem02WhisperGain = FMath::Clamp(1.0f - (CurrentHarmonics.CurrentSanity / 100.0f), 0.0f, 1.0f);
		CurrentHarmonics.MelodicDuckingDb = -18.0f * CurrentHarmonics.Stem02WhisperGain;
	}

	// 5. Broadcast Telemetry
	OnBladeHungerSanityShifted.Broadcast(CurrentHarmonics.BladeHunger01, CurrentHarmonics.CurrentSanity);
	OnDissonanceStemGainUpdated.Broadcast(CurrentHarmonics.Stem02WhisperGain, CurrentHarmonics.MelodicDuckingDb);
	OnSanityDissonanceTierChanged.Broadcast(CurrentHarmonics.DissonanceTier, CurrentHarmonics.HungerStage);
}

void UAshenBladeSanityConductorConvergenceSubsystem::TriggerFlowCatharsisPurge()
{
	const float RestoredAmount = 40.0f;
	CurrentHarmonics.CurrentSanity = FMath::Clamp(CurrentHarmonics.CurrentSanity + RestoredAmount, 0.0f, 100.0f);
	CurrentHarmonics.Stem02WhisperGain = 0.0f;
	CurrentHarmonics.MelodicDuckingDb = 0.0f;
	CurrentHarmonics.bFlowStateActive = true;

	OnFlowCatharsisTriggered.Broadcast(RestoredAmount);
}
