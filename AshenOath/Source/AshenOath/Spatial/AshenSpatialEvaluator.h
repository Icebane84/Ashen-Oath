// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Spatial/AshenSpatialTypes.h"
#include "AshenSpatialEvaluator.generated.h"

UCLASS()
class ASHENOATH_API UAshenSpatialEvaluator : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Pure vector flank alignment test:
	 * Vector from Enemy to Ally dotted against -EnemyForward.
	 * Returns 1.0 for an ally directly behind the enemy, -1.0 for an ally directly in front.
	 */
	UFUNCTION(BlueprintPure, Category = "Ashen|Spatial")
	static float ComputeFlankDot(const FVector& EnemyLocation, const FVector& EnemyForward, const FVector& AllyLocation);

	/**
	 * Evaluates all 5 predicates for companion synergy validation.
	 */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Spatial")
	static FAshenSpatialPredicateResult EvaluateSpatialSynergy(
		const FAshenSpatialSynergyQuery& Query,
		FVector& OutMotionWarpLocation,
		FRotator& OutMotionWarpRotation
	);
};
