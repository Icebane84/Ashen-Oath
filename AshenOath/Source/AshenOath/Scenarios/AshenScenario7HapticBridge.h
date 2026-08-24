// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario7Types.h"
#include "AshenScenario7HapticBridge.generated.h"

/**
 * UAshenScenario7HapticBridge
 * 
 * Maps extreme thermal heat vibrations (90Hz), molten trigger resistance, and magma geyser explosion rumbles to DualSense.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario7HapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario7HapticBridge();

	/** Evaluates DualSense haptic motor telemetry and trigger resistance */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario7|Haptics")
	void EvaluateCalderaHaptics(
		float HeatExhaustion01,
		float BladeTempC,
		ECalderaSurgePhase Phase,
		float& OutRightThermalPulse90Hz,
		float& OutLeftTriggerMoltenResistance,
		float& OutMagmaExplosionRumble) const;
};
