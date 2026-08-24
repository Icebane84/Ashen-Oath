// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenJournalTypes.h"
#include "AshenJournalHapticBridge.generated.h"

/**
 * UAshenJournalHapticBridge
 * 
 * Maps DualSense parchment turning page-snap resistance, 400Hz quill scribing micro-vibrations, and campfire ember pops.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenJournalHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenJournalHapticBridge();

	/** Evaluates DualSense tactile parameters for journal reading and campfire resting */
	UFUNCTION(BlueprintPure, Category = "Ashen|Journal|Haptics")
	void EvaluateJournalHaptics(
		bool bPageTurned,
		bool bWritingMarginalia,
		ECampfireReflectionMood Mood,
		float& OutTriggerPageSnapResistance,
		float& OutQuillVibration400Hz,
		float& OutEmberCrackleRumble);
};
