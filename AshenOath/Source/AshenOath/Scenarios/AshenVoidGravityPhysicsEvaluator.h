// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario9Types.h"
#include "AshenVoidGravityPhysicsEvaluator.generated.h"

/**
 * UAshenVoidGravityPhysicsEvaluator
 * 
 * Computes jump arc distance multipliers, airborne hang time, and downward kinetic strike force in void gravity.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenVoidGravityPhysicsEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenVoidGravityPhysicsEvaluator();

	/** Evaluates jump distance multiplier based on gravity scale [1.0x to 3.0x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario9|Gravity")
	float EvaluateJumpDistanceMultiplier(float GravityScale) const;

	/** Evaluates downward strike kinetic momentum amplification [1.0x to 2.5x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario9|Gravity")
	float EvaluateDownwardStrikeMultiplier(float GravityScale) const;
};
