// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenScenario7HapticBridge.h"

UAshenScenario7HapticBridge::UAshenScenario7HapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenScenario7HapticBridge::EvaluateCalderaHaptics(
	float HeatExhaustion01,
	float BladeTempC,
	ECalderaSurgePhase Phase,
	float& OutRightThermalPulse90Hz,
	float& OutLeftTriggerMoltenResistance,
	float& OutMagmaExplosionRumble) const
{
	// 90Hz thermal pulse scales with heat exhaustion & blade temperature
	const float BaseHeatHaptic = FMath::Clamp(HeatExhaustion01 * 0.70f, 0.0f, 0.70f);
	const float BladeHeatHaptic = FMath::Clamp((BladeTempC - 100.0f) / 700.0f * 0.30f, 0.0f, 0.30f);
	OutRightThermalPulse90Hz = BaseHeatHaptic + BladeHeatHaptic;

	// Molten resistance on left trigger increases with blade heat
	OutLeftTriggerMoltenResistance = FMath::Clamp(BladeTempC / 800.0f * 0.85f, 0.0f, 0.85f);

	// Magma explosion rumble
	if (Phase == ECalderaSurgePhase::ActiveEruption)
	{
		OutMagmaExplosionRumble = 0.95f;
	}
	else if (Phase == ECalderaSurgePhase::TelegraphWarning)
	{
		OutMagmaExplosionRumble = 0.45f;
	}
	else
	{
		OutMagmaExplosionRumble = 0.05f;
	}
}
