// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenTacticalMapHapticBridge.h"

UAshenTacticalMapHapticBridge::UAshenTacticalMapHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenTacticalMapHapticBridge::EvaluateMapHaptics(
	bool bMapOpen,
	float CursorEdgeDistance01,
	EWaypointBeaconState HoveredBeaconState,
	float& OutBoundaryTriggerResistance,
	float& OutBeaconPulseGain,
	float& OutTeleportSnapImpulse)
{
	if (!bMapOpen)
	{
		OutBoundaryTriggerResistance = 0.0f;
		OutBeaconPulseGain = 0.0f;
		OutTeleportSnapImpulse = 0.0f;
		return;
	}

	// Boundary drag friction as cursor nears border
	const float EdgeRatio = FMath::Clamp(CursorEdgeDistance01, 0.0f, 1.0f);
	OutBoundaryTriggerResistance = 0.20f + (EdgeRatio * 0.65f); // 0.20 to 0.85

	// Beacon pulse gain
	OutBeaconPulseGain = (HoveredBeaconState == EWaypointBeaconState::AttunedSanctuary) ? 0.75f :
		(HoveredBeaconState == EWaypointBeaconState::DiscoveredBeacon ? 0.35f : 0.0f);

	// Default impulse
	OutTeleportSnapImpulse = 0.0f;
}
