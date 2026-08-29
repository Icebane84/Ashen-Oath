// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCSEQuestBoardTypes.h"
#include "AshenCSEHapticBridge.generated.h"

/**
 * UAshenCSEHapticBridge
 * 
 * Maps DualSense smooth consensus resonance (60Hz low purr) vs ideological friction ticks (120Hz sharp pulses).
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCSEHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCSEHapticBridge();

	/** Evaluates DualSense haptic gains for cognitive dissonance */
	UFUNCTION(BlueprintPure, Category = "Ashen|CSE|Haptics")
	void EvaluateCSEHaptics(
		float DissonanceIndex,
		float& OutConsensusPurrGain,
		float& OutFrictionPulseGain);
};
