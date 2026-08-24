// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario10Types.h"
#include "AshenTripartiteApotheosisEvaluator.generated.h"

/**
 * UAshenTripartiteApotheosisEvaluator
 * 
 * Computes synchronized 3-character kinetic combo damage multipliers and party damage mitigation during Apotheosis.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTripartiteApotheosisEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTripartiteApotheosisEvaluator();

	/** Evaluates synchronized tripartite combo damage multiplier [1.0x to 4.0x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario10|Apotheosis")
	float EvaluateApotheosisDamageMultiplier(float Resonance01) const;

	/** Evaluates party incoming damage reduction percentage [0% to 75%] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario10|Apotheosis")
	float EvaluateApotheosisDamageReduction(float Resonance01) const;
};
