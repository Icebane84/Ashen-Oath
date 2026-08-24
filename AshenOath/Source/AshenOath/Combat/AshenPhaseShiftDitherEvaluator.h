// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenShroudKnightTypes.h"
#include "AshenPhaseShiftDitherEvaluator.generated.h"

/**
 * UAshenPhaseShiftDitherEvaluator
 * 
 * Computes runtime dithering opacity masks (1.0 vs 0.15), collision enable flags, and mist particle emission.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPhaseShiftDitherEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenPhaseShiftDitherEvaluator();

	/** Evaluates target dithering opacity mask [0.15 to 1.00] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Boss|Shader")
	float EvaluateDitherOpacity(EShroudKnightPhaseState PhaseState) const;

	/** Determines if boss collision is enabled */
	UFUNCTION(BlueprintPure, Category = "Ashen|Boss|Shader")
	bool IsCollisionEnabled(EShroudKnightPhaseState PhaseState) const;

	/** Evaluates mist trail particle density [0.0 to 100.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Boss|Shader")
	float EvaluateMistParticleDensity(EShroudKnightPhaseState PhaseState) const;
};
