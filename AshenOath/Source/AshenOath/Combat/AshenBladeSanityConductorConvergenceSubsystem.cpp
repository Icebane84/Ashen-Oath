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
	BalanceDataAsset = nullptr;
}

void UAshenBladeSanityConductorConvergenceSubsystem::UpdateConvergenceState(
	float DeltaSeconds,
	float NewHunger01,
	bool bInFlowState)
{
	CurrentHarmonics.BladeHunger01 = FMath::Clamp(NewHunger01, 0.0f, 1.0f);
	CurrentHarmonics.bFlowStateActive = bInFlowState;

	float DrainRatePerSec = 1.50f;
	float MaxWhisperGain = 1.0f;
	float MaxDuckingDb = -18.0f;

	if (BalanceDataAsset)
	{
		DrainRatePerSec = BalanceDataAsset->GetClampedBladeHunger().HungerSanityDrainRatePerSecond;
		MaxWhisperGain = BalanceDataAsset->GetClampedQuartzConductor().MaxStem02WhisperGain;
		MaxDuckingDb = BalanceDataAsset->GetClampedQuartzConductor().MaxMelodicDuckingDb;
	}

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

	// 2. Sanity Drain Calculation
	if (bInFlowState)
	{
		CurrentHarmonics.CurrentSanity = FMath::Clamp(CurrentHarmonics.CurrentSanity + (DeltaSeconds * 5.0f), 0.0f, 100.0f);
	}
	else
	{
		const float Drain = CurrentHarmonics.BladeHunger01 * DrainRatePerSec;
		CurrentHarmonics.CurrentSanity = FMath::Clamp(CurrentHarmonics.CurrentSanity - (DeltaSeconds * Drain), 0.0f, 100.0f);
	}

	// 3. Resolve Sanity Dissonance Tier
	const ESanityDissonanceTier PreviousTier = CurrentHarmonics.DissonanceTier;
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

	if (PreviousTier != CurrentHarmonics.DissonanceTier && OnSanityDissonanceTierChanged.IsBound())
	{
		OnSanityDissonanceTierChanged.Broadcast(CurrentHarmonics.DissonanceTier, CurrentHarmonics.HungerStage);
	}

	// 4. Resolve Stem 02 Whisper Gain & Melodic Stem Ducking
	if (bInFlowState)
	{
		CurrentHarmonics.Stem02WhisperGain = 0.0f;
		CurrentHarmonics.MelodicDuckingDb = 0.0f;
	}
	else
	{
		const float DissonanceScalar = 1.0f - (CurrentHarmonics.CurrentSanity / 100.0f);
		CurrentHarmonics.Stem02WhisperGain = DissonanceScalar * MaxWhisperGain;
		CurrentHarmonics.MelodicDuckingDb = DissonanceScalar * MaxDuckingDb;
	}

	if (OnBladeHungerSanityShifted.IsBound())
	{
		OnBladeHungerSanityShifted.Broadcast(CurrentHarmonics.BladeHunger01, CurrentHarmonics.CurrentSanity);
	}

	if (OnDissonanceStemGainUpdated.IsBound())
	{
		OnDissonanceStemGainUpdated.Broadcast(CurrentHarmonics.Stem02WhisperGain, CurrentHarmonics.MelodicDuckingDb);
	}
}

void UAshenBladeSanityConductorConvergenceSubsystem::TriggerFlowCatharsisPurge()
{
	float CatharsisHeal = 40.0f;
	float FlowDuration = 8.0f;

	if (BalanceDataAsset)
	{
		CatharsisHeal = BalanceDataAsset->GetClampedFlowCatharsis().InstantSanityHeal;
		FlowDuration = BalanceDataAsset->GetClampedFlowCatharsis().FlowDurationSeconds;
	}

	CurrentHarmonics.CurrentSanity = FMath::Clamp(CurrentHarmonics.CurrentSanity + CatharsisHeal, 0.0f, 100.0f);
	CurrentHarmonics.bFlowStateActive = true;
	CurrentHarmonics.Stem02WhisperGain = 0.0f;
	CurrentHarmonics.MelodicDuckingDb = 0.0f;

	// Recalculate tier after catharsis
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

	if (OnFlowCatharsisTriggered.IsBound())
	{
		OnFlowCatharsisTriggered.Broadcast(CatharsisHeal);
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenBladeSanityConductorConvergenceSubsystem: *** FLOW STATE CATHARSIS PURGE TRIGGERED *** (+%.1f Sanity, Duration: %.1fs, Whispers Muted)!"),
		CatharsisHeal, FlowDuration);
}
