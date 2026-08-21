// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario2SentinelsGambitTypes.h"
#include "AshenPathfindingDisruptionEvaluatorComponent.generated.h"

/**
 * UAshenPathfindingDisruptionEvaluatorComponent
 * 
 * Computes AI navigation breakdown, path obstruction scores, and LAW-001 circuit breaker state.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPathfindingDisruptionEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenPathfindingDisruptionEvaluatorComponent();

	/** Evaluates AI disruption tier based on active trap network density */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario2")
	EPathfindingDisruptionTier EvaluateDisruptionTier(float UtilityScore) const;

	/** Computes utility score degradation when navigating through a trap zone */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario2")
	float EvaluateDegradedUtility(float BaseUtility, int32 NearbyTrapCount) const;
};
