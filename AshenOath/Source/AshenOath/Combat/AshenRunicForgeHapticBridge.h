// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenRunicForgeTypes.h"
#include "AshenRunicForgeHapticBridge.generated.h"

/**
 * UAshenRunicForgeHapticBridge
 * 
 * Maps DualSense haptic motor vibrations: 0.85 heavy anvil hammer strike, steady resonant seam humming, and hybrid flow finisher pulse (0.95).
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRunicForgeHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRunicForgeHapticBridge();

	/** Evaluates DualSense haptic gains for forging and resonance */
	UFUNCTION(BlueprintPure, Category = "Ashen|RunicForge|Haptics")
	void EvaluateForgeHaptics(
		bool bAnvilStrike,
		bool bFlowResonating,
		float& OutHeavyMotorGain,
		float& OutLightMotorGain);
};
