// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "AshenOathbringerStanceHapticBridge.generated.h"

/**
 * UAshenOathbringerStanceHapticBridge
 * 
 * Maps DualSense haptic motor feedback for each stance: Vom Tag heavy sub-bass thud (0.90), Pflug rapid buzz, Ochs crisp parry click, and Mordhau blunt impact crunch.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathbringerStanceHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOathbringerStanceHapticBridge();

	/** Evaluates DualSense haptic parameters for active stance */
	UFUNCTION(BlueprintPure, Category = "Ashen|Oathbringer|Haptics")
	void EvaluateStanceHaptics(
		EOathbringerMartialStance Stance,
		bool bCleanFlowCancel,
		float& OutHeavyMotorGain,
		float& OutLightMotorGain);
};
