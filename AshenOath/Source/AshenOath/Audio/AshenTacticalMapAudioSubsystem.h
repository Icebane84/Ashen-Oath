// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "World/AshenTacticalMapTypes.h"
#include "AshenTacticalMapAudioSubsystem.generated.h"

/**
 * UAshenTacticalMapAudioSubsystem
 * 
 * MetaSounds audio subsystem synthesizing cartographic parchment rustles, 432Hz harmonic sanctuary beacon hums, and teleportation whooshes.
 */
UCLASS()
class ASHENOATH_API UAshenTacticalMapAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenTacticalMapAudioSubsystem();

	/** Evaluates 432Hz beacon harmonic resonance gain [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Map")
	float EvaluateBeaconResonanceGain(EWaypointBeaconState BeaconState) const;

	/** Evaluates teleportation whoosh frequency in Hz [200Hz to 1200Hz] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Map")
	float EvaluateTeleportWhooshFrequency(float ChannelProgress01) const;
};
