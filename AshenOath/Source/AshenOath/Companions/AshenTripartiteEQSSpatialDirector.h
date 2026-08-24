// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenTripartiteCognitiveLoopTypes.h"
#include "AshenTripartiteEQSSpatialDirector.generated.h"

/**
 * UAshenTripartiteEQSSpatialDirector
 * 
 * Computes dynamic Environment Query System (EQS) test weights and spatial offsets for Garrett and Serafina.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTripartiteEQSSpatialDirector : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTripartiteEQSSpatialDirector();

	/** Computes EQS target coordinates for Garrett's flank vector */
	UFUNCTION(BlueprintPure, Category = "Ashen|Tripartite|EQS")
	FVector ComputeGarrettTargetLocation(const FVector& KaelenLocation, const FVector& KaelenForward, float FlankAngleDeg, float DistanceUU) const;

	/** Computes EQS target coordinates for Serafina's support aura */
	UFUNCTION(BlueprintPure, Category = "Ashen|Tripartite|EQS")
	FVector ComputeSerafinaTargetLocation(const FVector& KaelenLocation, const FVector& KaelenForward, float DistanceUU) const;
};
