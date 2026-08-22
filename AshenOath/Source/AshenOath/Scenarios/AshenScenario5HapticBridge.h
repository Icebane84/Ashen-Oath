// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario5WeepingMireTypes.h"
#include "AshenScenario5HapticBridge.generated.h"

/**
 * UAshenScenario5HapticBridge
 * 
 * Maps heart palpitation tactile pulses and swamp sludge resistance to DualSense trigger motors.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario5HapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario5HapticBridge();

	/** Evaluates DualSense trigger resistance and heartbeat pulse intensity */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario5|Haptics")
	void EvaluateMireHaptics(
		EUnchainedVesselPhase Phase,
		bool bInDeepMud,
		float& OutTriggerResistance,
		float& OutHeartbeatPulseIntensity) const;
};
