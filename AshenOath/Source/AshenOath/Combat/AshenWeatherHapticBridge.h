// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDynamicWeatherTypes.h"
#include "AshenWeatherHapticBridge.generated.h"

/**
 * UAshenWeatherHapticBridge
 * 
 * Maps DualSense high-frequency rain tickles (120Hz), wind shear drag resistance (0.25 to 0.90), and lightning shock crackles to controller motors.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeatherHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWeatherHapticBridge();

	/** Evaluates DualSense haptics for active weather hazards */
	UFUNCTION(BlueprintPure, Category = "Ashen|Weather|Haptics")
	void EvaluateWeatherHaptics(
		EWeatherHazardState State,
		float WindShearMps,
		EWeatherShelterType Shelter,
		float& OutWindDragTriggerResistance,
		float& OutRainDropTickleGain,
		float& OutLightningShockImpulse);
};
