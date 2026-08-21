// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Haptics/AshenDualSenseHapticTypes.h"
#include "AshenDualSenseMetaSoundsSubsystem.generated.h"

/**
 * UAshenDualSenseMetaSoundsSubsystem
 * 
 * Manages audio submix sends to PS5 / PC DualSense controller speaker and haptic actuators.
 */
UCLASS()
class ASHENOATH_API UAshenDualSenseMetaSoundsSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenDualSenseMetaSoundsSubsystem();

	/** Evaluates speaker submix attenuation based on main volume */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Haptics")
	float EvaluateSpeakerGain(float MasterVolume, bool bSpeakerMuted) const;
};
