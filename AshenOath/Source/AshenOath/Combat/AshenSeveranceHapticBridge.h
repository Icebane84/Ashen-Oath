// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenSeveranceTypes.h"
#include "AshenSeveranceHapticBridge.generated.h"

/**
 * UAshenSeveranceHapticBridge
 * 
 * Maps DualSense haptic motor vibrations: 0.95 heavy bone-cleave resistance, arterial spray pulse (0.70), and adrenaline rush heartbeat thud.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSeveranceHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSeveranceHapticBridge();

	/** Evaluates DualSense haptic gains for severance and adrenaline surge */
	UFUNCTION(BlueprintPure, Category = "Ashen|Severance|Haptics")
	void EvaluateSeveranceHaptics(
		ESeveranceSeverityTier Severity,
		bool bAdrenalineSurging,
		float& OutHeavyMotorGain,
		float& OutLightMotorGain);
};
