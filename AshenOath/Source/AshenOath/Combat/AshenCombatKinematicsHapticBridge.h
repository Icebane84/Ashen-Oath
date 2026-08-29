// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenCombatKinematicsTypes.h"
#include "AshenCombatKinematicsHapticBridge.generated.h"

/**
 * UAshenCombatKinematicsHapticBridge
 * 
 * Maps DualSense adaptive trigger resistance (0.85 on cardiac exhaustion), heavy poise shatter rumble (0.95 at 30Hz), and crisp deflection clicks (0.80 at 220Hz).
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCombatKinematicsHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCombatKinematicsHapticBridge();

	/** Evaluates DualSense haptics for current combat kinematics */
	UFUNCTION(BlueprintPure, Category = "Ashen|Kinematics|Haptics")
	void EvaluateKinematicsHaptics(
		bool bInCardiacExhaustion,
		EPoiseStaggerState StaggerState,
		EParryRiposteQuality ParryQuality,
		float& OutTriggerResistance,
		float& OutStaggerMotorImpulse,
		float& OutDeflectionClickGain);
};
