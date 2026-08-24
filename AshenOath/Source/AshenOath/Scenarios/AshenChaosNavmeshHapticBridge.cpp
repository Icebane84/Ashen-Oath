// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenChaosNavmeshHapticBridge.h"

UAshenChaosNavmeshHapticBridge::UAshenChaosNavmeshHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenChaosNavmeshHapticBridge::EvaluateChaosHaptics(
	EChaosFractureSeverity Severity,
	float ImpactJoules,
	float DistanceToCollapseUU,
	float& OutLowFreqRumble,
	float& OutHighFreqCrunchTick,
	float& OutRubbleTriggerResistance) const
{
	// Distance attenuation: 1.0 at 0uu, drops to 0.0 at 1500uu
	const float DistanceFalloff = FMath::Clamp(1.0f - (DistanceToCollapseUU / 1500.0f), 0.0f, 1.0f);

	if (Severity == EChaosFractureSeverity::TotalDemolition)
	{
		OutLowFreqRumble = 0.90f * DistanceFalloff;
		OutHighFreqCrunchTick = 0.70f * DistanceFalloff;
		OutRubbleTriggerResistance = 0.80f;
	}
	else if (Severity == EChaosFractureSeverity::PartialCollapse)
	{
		OutLowFreqRumble = 0.50f * DistanceFalloff;
		OutHighFreqCrunchTick = 0.40f * DistanceFalloff;
		OutRubbleTriggerResistance = 0.40f;
	}
	else
	{
		OutLowFreqRumble = 0.15f * DistanceFalloff;
		OutHighFreqCrunchTick = 0.20f * DistanceFalloff;
		OutRubbleTriggerResistance = 0.0f;
	}
}
