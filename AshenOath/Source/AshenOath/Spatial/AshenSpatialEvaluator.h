// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Spatial/AshenSpatialTypes.h"
#include "AshenSpatialEvaluator.generated.h"

/**
 * UAshenSpatialEvaluator
 *
 * Vector-based geometric evaluation system validating companion orientation,
 * directional rear flank angle, and line-of-sight clearance.
 * (PRS-001-CDTC-001)
 */
UCLASS()
class ASHENOATH_API UAshenSpatialEvaluator : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Evaluates whether companion is in a valid kinetic flank vector and calculates motion warp target */
	UFUNCTION(BlueprintCallable, Category = "Ashen|SpatialAI")
	static bool EvaluateFlankConvexHull(
		const FAshenSpatialConvexHullQuery& Query,
		FVector& OutWarpLocation,
		FRotator& OutWarpRotation
	);
};
