// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenParasiticBladeHapticBridge.h"

UAshenParasiticBladeHapticBridge::UAshenParasiticBladeHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenParasiticBladeHapticBridge::EvaluateBladeHaptics(
	float BladeMassKg,
	float Corruption01,
	bool bGloomwoodFrozen,
	float& OutTriggerMassResistance,
	float& OutParasiticHeartbeatPulse,
	float& OutGloomwoodFreezeRumble)
{
	// Trigger resistance scales linearly with blade mass (45kg -> 0.20, 220kg -> 0.95)
	const float MassRatio = FMath::Clamp((BladeMassKg - 45.0f) / 175.0f, 0.0f, 1.0f);
	OutTriggerMassResistance = 0.20f + (0.75f * MassRatio);

	// Parasitic heartbeat pulse
	OutParasiticHeartbeatPulse = bGloomwoodFrozen ? 0.0f : (FMath::Clamp(Corruption01, 0.0f, 1.0f) * 0.80f);

	// Gloomwood needle freeze snap
	OutGloomwoodFreezeRumble = bGloomwoodFrozen ? 0.50f : 0.0f;
}
