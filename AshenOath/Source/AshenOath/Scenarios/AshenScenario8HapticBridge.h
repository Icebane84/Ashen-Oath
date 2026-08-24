// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario8Types.h"
#include "AshenScenario8HapticBridge.generated.h"

/**
 * UAshenScenario8HapticBridge
 * 
 * Maps tactile acoustic sonar ticks, lurking enemy heartbeats (40Hz), and radiant flare bursts to DualSense.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario8HapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario8HapticBridge();

	/** Evaluates DualSense haptic output for darkness fear, sonar ticks, and lurking heartbeats */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario8|Haptics")
	void EvaluateAbyssHaptics(
		ELightEnvironmentState LightState,
		float SonarRadiusUU,
		float LurkerProximityDistanceUU,
		float& OutLurkerHeartbeat40Hz,
		float& OutLeftTriggerDarknessFear,
		float& OutSonarTactileTick) const;
};
