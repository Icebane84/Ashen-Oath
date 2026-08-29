// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenForensicMindscapeTypes.h"
#include "AshenForensicMindscapeHapticBridge.generated.h"

/**
 * UAshenForensicMindscapeHapticBridge
 * 
 * Maps DualSense haptic motor vibrations: Lens magnifying focus tick (0.25), yarn thread pinning snap (0.65), and memory epiphany breakthrough surge (0.90).
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenForensicMindscapeHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenForensicMindscapeHapticBridge();

	/** Evaluates DualSense haptic gains for forensic actions */
	UFUNCTION(BlueprintPure, Category = "Ashen|Forensic|Haptics")
	void EvaluateForensicHaptics(
		EMemoryReconstructionState State,
		bool bPinningClue,
		float& OutHeavyMotorGain,
		float& OutLightMotorGain);
};
