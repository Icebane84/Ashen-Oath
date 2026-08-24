// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario9Types.h"
#include "AshenScenario9HapticBridge.generated.h"

/**
 * UAshenScenario9HapticBridge
 * 
 * Maps zero-g featherweight triggers, directional wind shear grip vibrations, and 528Hz bridge chimes to DualSense.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario9HapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario9HapticBridge();

	/** Evaluates DualSense haptic output for low gravity, wind gusts, and bridge resonance */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario9|Haptics")
	void EvaluateCitadelHaptics(
		float GravityScale,
		float WindSpeedMps,
		float BridgeStability01,
		float& OutTriggerResistance,
		float& OutLeftGripWindRumble,
		float& OutRightGripWindRumble,
		float& OutBridgeResonance528Hz) const;
};
