// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDynamicRubbleTypes.h"
#include "AshenRubblePhysicsHapticBridge.generated.h"

/**
 * UAshenRubblePhysicsHapticBridge
 * 
 * Maps DualSense low-frequency structural collapse rumble (35Hz) and demolition trigger resistance to hardware motors.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRubblePhysicsHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRubblePhysicsHapticBridge();

	/** Evaluates DualSense haptic feedback for environmental destruction events */
	UFUNCTION(BlueprintPure, Category = "Ashen|Rubble|Haptics")
	void EvaluateRubbleHaptics(
		EMasonryCollapseState CollapseState,
		EDemolitionToolType DemolitionTool,
		float RubbleMassKg,
		float& OutTriggerResistance,
		float& OutCollapseRumbleGain,
		float& OutDemolitionImpactPulse);
};
