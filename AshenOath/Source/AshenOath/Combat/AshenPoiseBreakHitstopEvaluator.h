// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenCombatKinematicsTypes.h"
#include "AshenPoiseBreakHitstopEvaluator.generated.h"

/**
 * UAshenPoiseBreakHitstopEvaluator
 * 
 * Evaluates hitstop time dilation (0.02x for 0.20s), camera trauma (+0.40), and riposte bonus damage (+25%).
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPoiseBreakHitstopEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenPoiseBreakHitstopEvaluator();

	/** Gets global hitstop time dilation factor [0.02x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Kinematics|Poise")
	float GetHitstopTimeDilation() const { return 0.02f; }

	/** Gets hitstop duration in real seconds [0.20s] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Kinematics|Poise")
	float GetHitstopDurationSeconds() const { return 0.20f; }

	/** Gets poise break camera trauma impulse [+0.40] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Kinematics|Poise")
	float GetPoiseBreakCameraTrauma() const { return 0.40f; }

	/** Gets perfect parry riposte damage bonus [+25%] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Kinematics|Poise")
	float GetRiposteDamageBonus() const { return 0.25f; }
};
