// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenSeveranceTypes.h"
#include "AshenSeverancePlaneEvaluator.generated.h"

/**
 * UAshenSeverancePlaneEvaluator
 * 
 * Computes cutting plane normals, procedural slice orientations, and ragdoll impulse vectors based on attack strike direction.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSeverancePlaneEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSeverancePlaneEvaluator();

	/** Evaluates cutting plane parameters from strike vector */
	UFUNCTION(BlueprintPure, Category = "Ashen|Severance|Evaluator")
	FSeveranceSlicePlaneData EvaluateSlicePlane(const FVector& HitLocation, const FVector& SwingTrajectory, ESeveranceBoneTarget BoneTarget) const;
};
