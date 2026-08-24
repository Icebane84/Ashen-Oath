// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenOathbringerParasiteSubsystem.h"

UAshenOathbringerParasiteSubsystem::UAshenOathbringerParasiteSubsystem()
{
	BladeState.Corruption01 = 0.15f;
	BladeState.BladeMassKg = 45.0f;
	BladeState.SwingDragPlayRate = 1.0f;
	BladeState.PommelGlowEmissive = 0.10f;
	BladeState.State = EBladeParasiteState::DormantSteel;
	BladeState.bGloomwoodFrozen = false;
	BladeState.GloomwoodTimeRemainingSeconds = 0.0f;
}

void UAshenOathbringerParasiteSubsystem::SetCorruption(float Corruption01)
{
	if (BladeState.bGloomwoodFrozen)
	{
		return; // Corruption frozen
	}

	BladeState.Corruption01 = FMath::Clamp(Corruption01, 0.0f, 1.0f);
	BladeState.BladeMassKg = 45.0f + (175.0f * BladeState.Corruption01);
	BladeState.SwingDragPlayRate = FMath::Clamp(1.0f - (0.55f * BladeState.Corruption01), 0.45f, 1.0f);
	BladeState.PommelGlowEmissive = FMath::Clamp(0.10f + (0.90f * BladeState.Corruption01), 0.10f, 1.0f);

	if (BladeState.Corruption01 >= 0.70f)
	{
		BladeState.State = EBladeParasiteState::ParasiticOvercharge;
	}
	else if (BladeState.Corruption01 >= 0.30f)
	{
		BladeState.State = EBladeParasiteState::AwakenedWhispers;
	}
	else
	{
		BladeState.State = EBladeParasiteState::DormantSteel;
	}

	OnParasiteStateChanged.Broadcast(BladeState.State, BladeState.Corruption01);
	OnBladeMassRecalculated.Broadcast(BladeState.BladeMassKg);
}

void UAshenOathbringerParasiteSubsystem::ApplyGloomwoodStabilization(float DurationSeconds)
{
	BladeState.bGloomwoodFrozen = true;
	BladeState.GloomwoodTimeRemainingSeconds = DurationSeconds;
	BladeState.State = EBladeParasiteState::GloomwoodFrozen;
	BladeState.BladeMassKg = FMath::Max(45.0f, BladeState.BladeMassKg - 80.0f);

	OnGloomwoodNeedleInjected.Broadcast(DurationSeconds);
	OnParasiteStateChanged.Broadcast(BladeState.State, BladeState.Corruption01);
	OnBladeMassRecalculated.Broadcast(BladeState.BladeMassKg);
}

void UAshenOathbringerParasiteSubsystem::TriggerWhisper(const FText& WhisperText, float VolumeMultiplier)
{
	OnEldrinWhisperTriggered.Broadcast(WhisperText, VolumeMultiplier);
}
