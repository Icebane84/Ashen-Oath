// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenKineticBerserkTypes.h"
#include "AshenKineticBerserkHapticBridge.generated.h"

/**
 * UAshenKineticBerserkHapticBridge
 * 
 * Maps structural cutting resistance, angular parry clash spikes, and sub-bass transients to DualSense motors.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenKineticBerserkHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenKineticBerserkHapticBridge();

	/** Evaluates DualSense trigger resistance and clash feedback based on kinetic state */
	UFUNCTION(BlueprintPure, Category = "Ashen|KineticBerserk|Haptics")
	void EvaluateKineticHaptics(
		float KineticJoules,
		float PlayRateModifier,
		float& OutTriggerResistance,
		float& OutSubBassGripVibration) const;
};
