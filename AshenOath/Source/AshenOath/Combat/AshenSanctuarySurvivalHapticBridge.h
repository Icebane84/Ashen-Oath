// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenSanctuarySurvivalTypes.h"
#include "AshenSanctuarySurvivalHapticBridge.generated.h"

/**
 * UAshenSanctuarySurvivalHapticBridge
 * 
 * Maps DualSense haptic motor vibrations: Rhythmic soothing warm hearth pulse (0.35), shivering teeth-chatter cold tremors (0.80), and meal digestion rumble.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSanctuarySurvivalHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSanctuarySurvivalHapticBridge();

	/** Evaluates DualSense haptic gains for survival states */
	UFUNCTION(BlueprintPure, Category = "Ashen|Survival|Haptics")
	void EvaluateSurvivalHaptics(
		EThermalShelterTier Tier,
		float BodyTempC,
		float& OutHeavyMotorGain,
		float& OutLightMotorGain);
};
