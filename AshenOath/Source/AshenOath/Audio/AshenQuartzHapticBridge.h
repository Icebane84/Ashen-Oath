// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Audio/AshenQuartzAudioTypes.h"
#include "AshenQuartzHapticBridge.generated.h"

/**
 * UAshenQuartzHapticBridge
 * 
 * Maps 115 BPM musical pulse ticks, tackle impact shockwaves, and Symbiotic Flow haptic vibrations to DualSense motors.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenQuartzHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenQuartzHapticBridge();

	/** Evaluates DualSense haptic trigger and motor pulses for Quartz audio events */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Haptics")
	void EvaluateQuartzHaptics(
		ECombatFlowState FlowState,
		EAlchemicalAudioFilter ActiveFilter,
		float& OutRhythmPulseGain,
		float& OutTackleImpactRumble,
		float& OutFlowStateHarmonicVibe);
};
