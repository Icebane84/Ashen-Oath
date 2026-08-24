// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenTripartiteHapticBridge.h"

UAshenTripartiteHapticBridge::UAshenTripartiteHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenTripartiteHapticBridge::EvaluateTripartiteHaptics(
	ETripartiteBehaviorMode Mode,
	float AttunementScore,
	float& OutLeftGripGarrettTick,
	float& OutRightGripSerafinaHum,
	float& OutSyncTriggerLock) const
{
	const float SafeScore = FMath::Clamp(AttunementScore, 0.0f, 1.0f);

	if (Mode == ETripartiteBehaviorMode::CombatEngagement)
	{
		OutLeftGripGarrettTick = 0.40f + (SafeScore * 0.40f);
		OutRightGripSerafinaHum = 0.30f + (SafeScore * 0.50f);
		OutSyncTriggerLock = (SafeScore >= 0.70f) ? 0.85f : 0.20f;
	}
	else if (Mode == ETripartiteBehaviorMode::ContemplativeSilence)
	{
		OutLeftGripGarrettTick = 0.10f;
		OutRightGripSerafinaHum = 0.15f;
		OutSyncTriggerLock = 0.0f;
	}
	else if (Mode == ETripartiteBehaviorMode::TraumaAftermath)
	{
		OutLeftGripGarrettTick = 0.0f;
		OutRightGripSerafinaHum = 0.0f;
		OutSyncTriggerLock = 0.50f; // Stiff trigger representing emotional barrier
	}
	else
	{
		OutLeftGripGarrettTick = 0.05f;
		OutRightGripSerafinaHum = 0.20f;
		OutSyncTriggerLock = 0.0f;
	}
}
