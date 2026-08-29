// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenCombatKinematicsConvergenceSubsystem.h"
#include "Kismet/GameplayStatics.h"

UAshenCombatKinematicsConvergenceSubsystem::UAshenCombatKinematicsConvergenceSubsystem()
{
	KinematicsState.CurrentEquipmentWeightKg = 25.0f;
	KinematicsState.MaxEquipLoadKg = 50.0f;
	KinematicsState.WeightClass = EAshenWeightClass::MediumLoad;
	KinematicsState.bInCardiacExhaustion = false;
	KinematicsState.SwingWindupSlowdown = 0.0f;
	KinematicsState.StaggerState = EPoiseStaggerState::SolidGuard;
	KinematicsState.bRiposteBuffActive = false;
}

void UAshenCombatKinematicsConvergenceSubsystem::UpdateKinematicsState(
	float CurrentWeightKg,
	float MaxLoadKg,
	float CurrentStaminaPercent,
	float CurrentPoisePercent)
{
	const float SafeMaxLoad = FMath::Max(1.0f, MaxLoadKg);
	const float WeightRatio = CurrentWeightKg / SafeMaxLoad;
	KinematicsState.CurrentEquipmentWeightKg = CurrentWeightKg;
	KinematicsState.MaxEquipLoadKg = SafeMaxLoad;

	// 1. Resolve Weight Class
	EAshenWeightClass NewWeightClass = EAshenWeightClass::MediumLoad;
	if (WeightRatio > 1.0f)
	{
		NewWeightClass = EAshenWeightClass::Overburdened;
	}
	else if (WeightRatio > 0.70f)
	{
		NewWeightClass = EAshenWeightClass::HeavyLoad;
	}
	else if (WeightRatio <= 0.30f)
	{
		NewWeightClass = EAshenWeightClass::LightLoad;
	}

	if (NewWeightClass != KinematicsState.WeightClass)
	{
		KinematicsState.WeightClass = NewWeightClass;
		OnWeightClassChanged.Broadcast(NewWeightClass, WeightRatio);
	}

	// 2. Cardiac Exhaustion (<35% Stamina)
	const bool bWasExhausted = KinematicsState.bInCardiacExhaustion;
	KinematicsState.bInCardiacExhaustion = (CurrentStaminaPercent < 0.35f);
	KinematicsState.SwingWindupSlowdown = KinematicsState.bInCardiacExhaustion ? 0.25f : 0.0f;

	if (bWasExhausted != KinematicsState.bInCardiacExhaustion)
	{
		OnCardiacExhaustionToggled.Broadcast(KinematicsState.bInCardiacExhaustion);
	}

	// 3. Poise Stagger State
	if (CurrentPoisePercent <= 0.0f)
	{
		KinematicsState.StaggerState = EPoiseStaggerState::PoiseBroken;
	}
	else if (CurrentPoisePercent <= 0.30f)
	{
		KinematicsState.StaggerState = EPoiseStaggerState::UnsteadyGuard;
	}
	else
	{
		KinematicsState.StaggerState = EPoiseStaggerState::SolidGuard;
	}
}

void UAshenCombatKinematicsConvergenceSubsystem::TriggerPoiseBreakHitstop(AActor* TargetActor)
{
	const float HitstopDilation = 0.02f; // 0.02x speed for 0.20s
	KinematicsState.StaggerState = EPoiseStaggerState::PoiseBroken;
	OnPoiseBreakTriggered.Broadcast(TargetActor, HitstopDilation);
}

void UAshenCombatKinematicsConvergenceSubsystem::TriggerPerfectParrySurge()
{
	const float StaminaRestored = 50.0f;
	const float WhiteFlameGain = 35.0f;
	const float RiposteBonusDmg = 0.25f; // +25% bonus riposte damage

	KinematicsState.bRiposteBuffActive = true;
	OnPerfectParrySurgeTriggered.Broadcast(StaminaRestored, WhiteFlameGain, RiposteBonusDmg);
}
