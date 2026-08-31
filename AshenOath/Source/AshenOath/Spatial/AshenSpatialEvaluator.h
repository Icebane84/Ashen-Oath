// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Spatial/AshenSpatialTypes.h"
#include "AshenSpatialEvaluator.generated.h"

UENUM(BlueprintType)
enum class EAshenCompanionState : uint8
{
	Normal,
	HitStun,
	Downed,
	Interrupted
};

/** Per-predicate breakdown exposed for debugging, telemetry, and CI/CD verification */
USTRUCT(BlueprintType)
struct FAshenSpatialTelemetry
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Spatial") bool bDistanceValid = false;
	UPROPERTY(BlueprintReadOnly, Category = "Spatial") bool bFlankValid = false;
	UPROPERTY(BlueprintReadOnly, Category = "Spatial") bool bLineOfSightValid = false;
	UPROPERTY(BlueprintReadOnly, Category = "Spatial") bool bNavigationValid = false;
	UPROPERTY(BlueprintReadOnly, Category = "Spatial") bool bStateValid = false;

	UPROPERTY(BlueprintReadOnly, Category = "Spatial") float DistanceUU = 0.0f;
	UPROPERTY(BlueprintReadOnly, Category = "Spatial") float FlankDot = 0.0f;

	bool IsFullyValid() const
	{
		return bDistanceValid && bFlankValid && bLineOfSightValid && bNavigationValid && bStateValid;
	}
};

/**
 * URelationalSpatialEvaluator
 *
 * Vector-based geometric evaluation system validating companion orientation,
 * directional rear flank angle, and line-of-sight clearance.
 * (PRS-001-CDTC-001-V2)
 */
UCLASS(BlueprintType)
class ASHENOATH_API URelationalSpatialEvaluator : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "Spatial|Tuning")
	float MaxSynergyDistanceUU = 250.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Spatial|Tuning")
	float FlankHalfAngleDegrees = 45.0f;

	UFUNCTION(BlueprintCallable, Category = "Spatial")
	FAshenSpatialTelemetry EvaluateSynergy(
		const AActor* Ally,
		const AActor* Enemy,
		const FVector& WarpTarget,
		EAshenCompanionState AllyState
	) const;

	/**
	 * Pure flank-dot computation, exposed statically so QA can validate the corrected
	 * convention with plain FVectors -- no world, actors, or traces required.
	 * Points strictly from Enemy -> Ally.
	 */
	UFUNCTION(BlueprintCallable, Category = "Spatial", meta = (BlueprintThreadSafe))
	static float ComputeFlankDot(const FVector& AllyLocation, const FVector& EnemyLocation, const FVector& EnemyForward);

private:
	bool CheckLineOfSight(const AActor* Ally, const AActor* Enemy) const;
	bool CheckNavigation(const AActor* Ally, const FVector& WarpTarget) const;
};

/**
 * UAshenSpatialEvaluator
 *
 * Blueprint Function Library adapter for quick query execution.
 */
UCLASS()
class ASHENOATH_API UAshenSpatialEvaluator : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Ashen|SpatialAI")
	static bool EvaluateFlankConvexHull(
		const FAshenSpatialConvexHullQuery& Query,
		FVector& OutWarpLocation,
		FRotator& OutWarpRotation
	);
};
