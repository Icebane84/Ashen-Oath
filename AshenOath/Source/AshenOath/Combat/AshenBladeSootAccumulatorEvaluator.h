// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenAlchemicalSlagTypes.h"
#include "AshenBladeSootAccumulatorEvaluator.generated.h"

/**
 * UAshenBladeSootAccumulatorEvaluator
 * 
 * Computes incremental soot accumulation from heavy cleaves (+0.05) and corrupted beast executions (+0.15), and determines surface state transitions.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBladeSootAccumulatorEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBladeSootAccumulatorEvaluator();

	/** Evaluates soot gained from landing an attack */
	UFUNCTION(BlueprintPure, Category = "Ashen|AlchemicalSlag|Evaluator")
	float EvaluateStrikeSootGain(bool bIsHeavyCleave) const;

	/** Evaluates soot gained from an enemy execution */
	UFUNCTION(BlueprintPure, Category = "Ashen|AlchemicalSlag|Evaluator")
	float EvaluateExecutionSootGain() const;

	/** Evaluates whether blade reaches superheated threshold [>=0.80] */
	UFUNCTION(BlueprintPure, Category = "Ashen|AlchemicalSlag|Evaluator")
	bool IsSuperheatedSlag(float SootLevel) const;
};
