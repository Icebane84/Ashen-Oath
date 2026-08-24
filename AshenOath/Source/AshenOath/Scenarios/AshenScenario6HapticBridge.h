// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario6Types.h"
#include "AshenScenario6HapticBridge.generated.h"

/**
 * UAshenScenario6HapticBridge
 * 
 * Maps sub-zero shivering vibrations (Left Grip) and roaring hearth flame warmth (Right Grip) to DualSense motors.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario6HapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario6HapticBridge();

	/** Evaluates left/right grip haptic amplitudes and trigger resistance */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario6|Haptics")
	void EvaluateScenario6Haptics(
		float FrostbiteGauge,
		float HearthIgnition,
		bool bInWarmth,
		float& OutLeftGripFrostShiver,
		float& OutRightGripHearthWarmth,
		float& OutFrozenTriggerResistance) const;
};
