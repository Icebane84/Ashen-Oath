// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDestructionWeatherAITypes.h"
#include "AshenDestructionCoverDurabilityEvaluator.generated.h"

/**
 * UAshenDestructionCoverDurabilityEvaluator
 * 
 * Computes cover structural integrity (500 HP baseline), acid rain degradation, and explosive shrapnel blast damage upon cover collapse.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDestructionCoverDurabilityEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDestructionCoverDurabilityEvaluator();

	/** Evaluates remaining cover health after damage */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Evaluator")
	float EvaluateRemainingCoverHP(float CurrentHP, float IncomingDamage) const;

	/** Evaluates explosive shrapnel damage on cover collapse [250 Dmg] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Evaluator")
	float EvaluateShrapnelDamage(float MaxCoverHP) const;

	/** Evaluates shrapnel blast radius [250uu] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Evaluator")
	float EvaluateShrapnelRadiusUU() const { return 250.0f; }
};
