// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenShroudKnightBossSubsystem.h"

UAshenShroudKnightBossSubsystem::UAshenShroudKnightBossSubsystem()
{
	MaxBossHealth = 10000.0f;
	CurrentBossHealth = 10000.0f;
	BossState.HealthPercent = 1.0f;
	BossState.ParanoiaInfection01 = 0.10f;
	BossState.DitherOpacity = 1.0f;
	BossState.PhaseState = EShroudKnightPhaseState::PhysicalSolid;
	BossState.ParanoiaTier = EParanoiaInfectionTier::ClearMind;
	BossState.TrinityStep = ETrinityStrikeStep::None;
}

void UAshenShroudKnightBossSubsystem::ApplyBossDamage(float DamageAmount)
{
	if (BossState.PhaseState == EShroudKnightPhaseState::SpectralPhasing)
	{
		// Intangible to normal attacks (90% damage reduction)
		DamageAmount *= 0.10f;
	}

	CurrentBossHealth = FMath::Clamp(CurrentBossHealth - DamageAmount, 0.0f, MaxBossHealth);
	BossState.HealthPercent = CurrentBossHealth / MaxBossHealth;

	if (CurrentBossHealth <= 0.0f)
	{
		OnTrinityStrikeCompleted.Broadcast(DamageAmount, true);
	}
}

void UAshenShroudKnightBossSubsystem::SetPhaseState(EShroudKnightPhaseState NewState)
{
	BossState.PhaseState = NewState;
	BossState.DitherOpacity = (NewState == EShroudKnightPhaseState::SpectralPhasing) ? 0.15f : 1.0f;

	OnShroudKnightPhaseChanged.Broadcast(BossState.PhaseState, BossState.DitherOpacity);
}

void UAshenShroudKnightBossSubsystem::AdvanceTrinityStep(ETrinityStrikeStep Step)
{
	BossState.TrinityStep = Step;
	OnTrinityStrikeProgressed.Broadcast(Step);

	if (Step == ETrinityStrikeStep::GarrettThreadLock)
	{
		SetPhaseState(EShroudKnightPhaseState::ThreadAnchored);
	}
	else if (Step == ETrinityStrikeStep::SerafinaPurgeBeam)
	{
		// Trinity Finisher (3.5x burst damage)
		const float FinisherDmg = 3500.0f;
		ApplyBossDamage(FinisherDmg);
		OnTrinityStrikeCompleted.Broadcast(FinisherDmg, CurrentBossHealth <= 0.0f);
		BossState.TrinityStep = ETrinityStrikeStep::None;
	}
}

void UAshenShroudKnightBossSubsystem::AdjustParanoiaInfection(float DeltaInfection)
{
	BossState.ParanoiaInfection01 = FMath::Clamp(BossState.ParanoiaInfection01 + DeltaInfection, 0.0f, 1.0f);

	if (BossState.ParanoiaInfection01 >= 0.75f)
	{
		BossState.ParanoiaTier = EParanoiaInfectionTier::FullPsychosis;
	}
	else if (BossState.ParanoiaInfection01 >= 0.50f)
	{
		BossState.ParanoiaTier = EParanoiaInfectionTier::VignetteTerror;
	}
	else if (BossState.ParanoiaInfection01 >= 0.25f)
	{
		BossState.ParanoiaTier = EParanoiaInfectionTier::PeripheralEchoes;
	}
	else
	{
		BossState.ParanoiaTier = EParanoiaInfectionTier::ClearMind;
	}

	OnParanoiaInfectionChanged.Broadcast(BossState.ParanoiaInfection01, BossState.ParanoiaTier);
}
