// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenCampfireCookingTypes.h"
#include "AshenCampfireCookingHapticBridge.generated.h"

/**
 * UAshenCampfireCookingHapticBridge
 * 
 * Maps DualSense low-frequency soul-ember crackles (25Hz) and stirring viscosity resistance to controller motors.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCampfireCookingHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCampfireCookingHapticBridge();

	/** Evaluates DualSense haptics for cooking and resting */
	UFUNCTION(BlueprintPure, Category = "Ashen|Cooking|Haptics")
	void EvaluateCookingHaptics(
		ECookingPotState PotState,
		float TemperatureCelsius,
		float& OutStirringResistance,
		float& OutWarmthCrackleGain,
		float& OutMealServedChime);
};
