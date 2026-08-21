// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Tactics/AshenCoOpComboSynchronizerComponent.h"

UAshenCoOpComboSynchronizerComponent::UAshenCoOpComboSynchronizerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FTemporalComboExecutionState UAshenCoOpComboSynchronizerComponent::EvaluateComboSync(
	int32 ParticipantCount,
	float TimingDeltaSeconds,
	float MaxWindowSeconds) const
{
	FTemporalComboExecutionState State;
	State.ActiveParticipants = FMath::Clamp(ParticipantCount, 1, 3);
	State.ComboSyncWindowSeconds = MaxWindowSeconds;

	if (TimingDeltaSeconds <= MaxWindowSeconds && ParticipantCount >= 2)
	{
		State.bIsSynchronized = true;
		// 2 participants = 1.8x, 3 participants = 2.5x damage
		State.DamageMultiplier = (ParticipantCount == 3) ? 2.50f : 1.80f;
	}
	else
	{
		State.bIsSynchronized = false;
		State.DamageMultiplier = 1.0f;
	}

	return State;
}
