// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenAlchemicalSlagTypes.h"
#include "AshenThermalReactionEvaluator.generated.h"

/**
 * UAshenThermalReactionEvaluator
 * 
 * Computes reaction damage scales, blast radiuses, poise multipliers, and status debuffs for the 4 elemental/thermal chemical combos.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenThermalReactionEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenThermalReactionEvaluator();

	/** Solves reaction parameters given blade state and target environmental conditions */
	UFUNCTION(BlueprintPure, Category = "Ashen|AlchemicalSlag|Evaluator")
	FThermalReactionResult EvaluateReaction(
		EOathbringerBladeSurfaceState SurfaceState,
		EAlchemicalBladeCoating Coating,
		bool bTargetChilled,
		bool bTargetInAcidRain,
		bool bTargetInLightningStorm) const;
};
