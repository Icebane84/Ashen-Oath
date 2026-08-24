// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenShroudKnightTypes.h"
#include "AshenShroudKnightHapticBridge.generated.h"

/**
 * UAshenShroudKnightHapticBridge
 * 
 * Maps DualSense adaptive trigger resistance and haptic vibration motors for Shroud-Knight phase-shifting, paranoia, and Trinity finisher.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenShroudKnightHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenShroudKnightHapticBridge();

	/** Evaluates DualSense haptic trigger resistance and rumble */
	UFUNCTION(BlueprintPure, Category = "Ashen|Boss|Haptics")
	void EvaluateBossHaptics(
		EShroudKnightPhaseState PhaseState,
		float Infection01,
		ETrinityStrikeStep TrinityStep,
		float& OutTriggerResistance,
		float& OutParanoiaJitterRumble,
		float& OutFinisherImpactGain);
};
