// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenChaosNavmeshTypes.h"
#include "AshenChaosNavmeshHapticBridge.generated.h"

/**
 * UAshenChaosNavmeshHapticBridge
 * 
 * Maps low-frequency structural collapse rumbles (30Hz) and stone impact crunch vibrations to DualSense controller motors.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenChaosNavmeshHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenChaosNavmeshHapticBridge();

	/** Evaluates DualSense haptic rumble intensity and trigger crunch resistance */
	UFUNCTION(BlueprintPure, Category = "Ashen|Chaos|Haptics")
	void EvaluateChaosHaptics(
		EChaosFractureSeverity Severity,
		float ImpactJoules,
		float DistanceToCollapseUU,
		float& OutLowFreqRumble,
		float& OutHighFreqCrunchTick,
		float& OutRubbleTriggerResistance) const;
};
