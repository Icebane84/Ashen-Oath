// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario10Types.h"
#include "AshenScenario10HapticBridge.generated.h"

/**
 * UAshenScenario10HapticBridge
 * 
 * Maps 60 BPM synchronized DualSense trigger pulses, Left/Right motor harmonic balance (639Hz vs 396Hz), and iridescent LED color.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario10HapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario10HapticBridge();

	/** Evaluates DualSense haptic and LED state for apotheosis */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario10|Haptics")
	void EvaluateZenithHaptics(
		float Resonance01,
		float TrustScore01,
		float Debt01,
		float& OutSynchronizedTriggerPulse60BPM,
		float& OutLeftMotorPurity639Hz,
		float& OutRightMotorKinetic396Hz,
		FLinearColor& OutTouchpadLEDColor) const;
};
