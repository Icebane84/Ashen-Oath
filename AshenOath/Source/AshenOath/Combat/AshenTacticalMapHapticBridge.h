// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenTacticalMapTypes.h"
#include "AshenTacticalMapHapticBridge.generated.h"

/**
 * UAshenTacticalMapHapticBridge
 * 
 * Maps DualSense parchment boundary drag friction (0.20 to 0.85), beacon attunement heartbeat pulses, and teleport snaps.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTacticalMapHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTacticalMapHapticBridge();

	/** Evaluates DualSense haptics for map cursor and travel triggers */
	UFUNCTION(BlueprintPure, Category = "Ashen|Map|Haptics")
	void EvaluateMapHaptics(
		bool bMapOpen,
		float CursorEdgeDistance01,
		EWaypointBeaconState HoveredBeaconState,
		float& OutBoundaryTriggerResistance,
		float& OutBeaconPulseGain,
		float& OutTeleportSnapImpulse);
};
