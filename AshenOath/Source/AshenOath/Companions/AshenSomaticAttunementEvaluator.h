// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenTripartiteCognitiveLoopTypes.h"
#include "AshenSomaticAttunementEvaluator.generated.h"

/**
 * UAshenSomaticAttunementEvaluator
 * 
 * Computes tripartite attunement score (0.0 to 1.0) and evaluates finisher damage scaling multiplier.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticAttunementEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticAttunementEvaluator();

	/** Computes finisher damage multiplier from attunement score [1.0x to 3.0x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Tripartite")
	float EvaluateFinisherDamageMultiplier(float AttunementScore) const;

	/** Categorizes attunement phase from raw score */
	UFUNCTION(BlueprintPure, Category = "Ashen|Tripartite")
	ECompanionAttunementPhase ClassifyAttunementPhase(float AttunementScore) const;
};
