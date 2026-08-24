// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenTripartiteCognitiveLoopTypes.h"
#include "AshenTripartiteHapticBridge.generated.h"

/**
 * UAshenTripartiteHapticBridge
 * 
 * Maps Garrett's flank tactile ticks (Left Grip) and Serafina's empathic aura hums (Right Grip) to DualSense motors.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTripartiteHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTripartiteHapticBridge();

	/** Evaluates left/right grip haptic amplitudes and trigger resistance */
	UFUNCTION(BlueprintPure, Category = "Ashen|Tripartite|Haptics")
	void EvaluateTripartiteHaptics(
		ETripartiteBehaviorMode Mode,
		float AttunementScore,
		float& OutLeftGripGarrettTick,
		float& OutRightGripSerafinaHum,
		float& OutSyncTriggerLock) const;
};
