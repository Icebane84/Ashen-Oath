// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDestructionWeatherAITypes.h"
#include "AshenConductiveLightningArcEvaluator.generated.h"

/**
 * UAshenConductiveLightningArcEvaluator
 * 
 * Evaluates electrical propagation across metallic rubble and acid rain puddles, calculating chain shock damage and paralysis stagger durations.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenConductiveLightningArcEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenConductiveLightningArcEvaluator();

	/** Evaluates whether surface conducts electricity */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Evaluator")
	bool IsSurfaceConductive(EConductiveSurfaceType SurfaceType) const;

	/** Evaluates chain-lightning shock damage */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Evaluator")
	float EvaluateChainShockDamage(EConductiveSurfaceType SurfaceType) const;

	/** Evaluates paralysis stagger duration in seconds [1.2s on conductive hit] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Evaluator")
	float EvaluateParalysisStaggerSeconds(EConductiveSurfaceType SurfaceType) const;
};
