// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario4WhisperwoodTypes.h"
#include "AshenScenario4HapticBridge.generated.h"

/**
 * UAshenScenario4HapticBridge
 * 
 * Maps touchpad soot swipe friction and auditory whisper pulses to DualSense haptics.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario4HapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario4HapticBridge();

	/** Evaluates touchpad soot swipe haptic rumble intensity */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario4|Haptics")
	float EvaluateSootSwipeHapticIntensity(float SwipeVelocity, float RemainingSoot) const;
};
