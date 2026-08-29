// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenRunicForgeTypes.h"
#include "AshenSigilResonanceEvaluator.generated.h"

/**
 * UAshenSigilResonanceEvaluator
 * 
 * Computes hybrid dual-sigil finisher strike damage scaling (1.40x), suction gravity radiuses, and poise shatter values.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSigilResonanceEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSigilResonanceEvaluator();

	/** Evaluates hybrid finisher bonus damage multiplier */
	UFUNCTION(BlueprintPure, Category = "Ashen|RunicForge|Evaluator")
	float EvaluateHybridFinisherDamage(ESigilResonanceEffect SigilA, ESigilResonanceEffect SigilB) const;

	/** Evaluates whether two socketed sigils can create a Flow Resonance strike */
	UFUNCTION(BlueprintPure, Category = "Ashen|RunicForge|Evaluator")
	bool CanTriggerResonance(ESigilResonanceEffect SigilA, ESigilResonanceEffect SigilB) const;
};
