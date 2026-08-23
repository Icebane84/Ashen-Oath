// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenBleedingWaystationTypes.h"
#include "AshenWaystationHapticBridge.generated.h"

/**
 * UAshenWaystationHapticBridge
 * 
 * Maps Garrett's twin-blade X-lock torque and Kaelen's panic tremors to DualSense adaptive triggers.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWaystationHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWaystationHapticBridge();

	/** Evaluates DualSense trigger resistance and tactile tremor intensity */
	UFUNCTION(BlueprintPure, Category = "Ashen|Waystation|Haptics")
	void EvaluateWaystationHaptics(
		EWaystationRunMode Mode,
		float& OutLeftTriggerResistance,
		float& OutRightTactileTremor) const;
};
