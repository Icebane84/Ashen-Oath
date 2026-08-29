// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDestructionWeatherAITypes.h"
#include "AshenDestructionWeatherAIHapticBridge.generated.h"

/**
 * UAshenDestructionWeatherAIHapticBridge
 * 
 * Maps DualSense thunder strike sub-bass punch (0.95 heavy motor), sizzling electrical chain-arc tingle (150Hz), and rubble debris crunches.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDestructionWeatherAIHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDestructionWeatherAIHapticBridge();

	/** Evaluates DualSense haptic motor intensities */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Haptics")
	void EvaluateTacticalHaptics(
		bool bDirectLightningStrike,
		bool bConductiveArcChained,
		bool bCoverCollapsed,
		float& OutHeavyMotorPunch,
		float& OutLightMotorTingle);
};
