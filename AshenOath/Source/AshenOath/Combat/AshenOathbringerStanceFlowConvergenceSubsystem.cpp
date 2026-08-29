// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenOathbringerStanceFlowConvergenceSubsystem.h"

UAshenOathbringerStanceFlowConvergenceSubsystem::UAshenOathbringerStanceFlowConvergenceSubsystem()
{
	CurrentStance = EOathbringerMartialStance::VomTag_HighWrath;
	UpdateKinematicsForStance(CurrentStance);
}

void UAshenOathbringerStanceFlowConvergenceSubsystem::SwitchStance(
	EOathbringerMartialStance NewStance)
{
	if (CurrentStance != NewStance)
	{
		CurrentStance = NewStance;
		UpdateKinematicsForStance(CurrentStance);

		OnOathbringerStanceChanged.Broadcast(CurrentStance, CurrentKinematics);
		OnRunicSeamColorUpdated.Broadcast(CurrentKinematics.RunicSeamColor, 4.0f);
	}
}

EFlowChainingTimingQuality UAshenOathbringerStanceFlowConvergenceSubsystem::AttemptFlowCancel(
	EOathbringerMartialStance TargetStance,
	float CurrentRecoveryElapsedSeconds)
{
	if (FlowWindowData.bWindowActive &&
		CurrentRecoveryElapsedSeconds >= FlowWindowData.WindowStartSeconds &&
		CurrentRecoveryElapsedSeconds <= (FlowWindowData.WindowStartSeconds + FlowWindowData.WindowDurationSeconds))
	{
		// Clean flow glint timing achieved
		SwitchStance(TargetStance);
		FlowWindowData.bWindowActive = false;
		FlowWindowData.CurrentFlowCharge = FMath::Clamp(FlowWindowData.CurrentFlowCharge + 15.0f, 0.0f, 100.0f);

		OnFlowChainingGlintTriggered.Broadcast(EFlowChainingTimingQuality::FlowGlintClean, 15.0f);
		return EFlowChainingTimingQuality::FlowGlintClean;
	}

	// Missed timing
	SwitchStance(TargetStance);
	FlowWindowData.bWindowActive = false;
	OnFlowChainingGlintTriggered.Broadcast(EFlowChainingTimingQuality::MissedTiming, 0.0f);
	return EFlowChainingTimingQuality::MissedTiming;
}

void UAshenOathbringerStanceFlowConvergenceSubsystem::OpenFlowGlintWindow(
	float StartTimeSeconds,
	float DurationSeconds)
{
	FlowWindowData.bWindowActive = true;
	FlowWindowData.WindowStartSeconds = StartTimeSeconds;
	FlowWindowData.WindowDurationSeconds = DurationSeconds;
}

void UAshenOathbringerStanceFlowConvergenceSubsystem::UpdateKinematicsForStance(
	EOathbringerMartialStance Stance)
{
	CurrentKinematics.Stance = Stance;

	switch (Stance)
	{
	case EOathbringerMartialStance::VomTag_HighWrath:
		CurrentKinematics.DamageMultiplier = 1.40f;
		CurrentKinematics.PoiseDamageMultiplier = 1.40f;
		CurrentKinematics.StaminaCost = 35.0f;
		CurrentKinematics.ParryWindowSeconds = 0.08f;
		CurrentKinematics.ArmorPenetrationPercent = 0.20f;
		CurrentKinematics.RunicSeamColor = FLinearColor(1.0f, 0.15f, 0.05f, 1.0f); // Crimson Embers
		break;

	case EOathbringerMartialStance::Pflug_LowPlow:
		CurrentKinematics.DamageMultiplier = 1.00f;
		CurrentKinematics.PoiseDamageMultiplier = 0.90f;
		CurrentKinematics.StaminaCost = 14.0f; // -30% stamina reduction
		CurrentKinematics.ParryWindowSeconds = 0.10f;
		CurrentKinematics.ArmorPenetrationPercent = 0.35f;
		CurrentKinematics.RunicSeamColor = FLinearColor(0.9f, 0.95f, 1.0f, 1.0f); // White Flame
		break;

	case EOathbringerMartialStance::Ochs_CrownGuard:
		CurrentKinematics.DamageMultiplier = 1.10f;
		CurrentKinematics.PoiseDamageMultiplier = 1.15f;
		CurrentKinematics.StaminaCost = 20.0f;
		CurrentKinematics.ParryWindowSeconds = 0.22f; // +0.12s leniency
		CurrentKinematics.ArmorPenetrationPercent = 0.15f;
		CurrentKinematics.RunicSeamColor = FLinearColor(1.0f, 0.85f, 0.2f, 1.0f); // Gold Shimmer
		break;

	case EOathbringerMartialStance::Mordhau_HalfSword:
	default:
		CurrentKinematics.DamageMultiplier = 1.25f;
		CurrentKinematics.PoiseDamageMultiplier = 1.75f; // +75% shield shatter
		CurrentKinematics.StaminaCost = 28.0f;
		CurrentKinematics.ParryWindowSeconds = 0.10f;
		CurrentKinematics.ArmorPenetrationPercent = 1.00f; // 100% Armor Penetration
		CurrentKinematics.RunicSeamColor = FLinearColor(0.35f, 0.1f, 0.6f, 1.0f); // Umbral Shock
		break;
	}
}
