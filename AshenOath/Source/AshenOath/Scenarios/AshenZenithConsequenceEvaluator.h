// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario10Types.h"
#include "AshenZenithConsequenceEvaluator.generated.h"

/**
 * UAshenZenithConsequenceEvaluator
 * 
 * Analyzes campaign telemetry (Trust, Debt, Trauma, Soot) to evaluate the canonical Grand Zenith consequence ending.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenZenithConsequenceEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenZenithConsequenceEvaluator();

	/** Evaluates the endgame consequence ending based on party metrics */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario10|Consequence")
	EZenithConsequenceEnding EvaluateConsequenceEnding(
		float TrustScore01,
		float IntegrationDebt01,
		bool bBerserkDominant) const;

	/** Evaluates tripartite alignment tier */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario10|Consequence")
	ETripartiteAlignmentTier EvaluateAlignmentTier(float TrustScore01) const;
};
