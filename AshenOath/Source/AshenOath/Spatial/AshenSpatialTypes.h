// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "AshenSpatialTypes.generated.h"

/**
 * FAshenSpatialSynergyQuery
 *
 * Query parameters for evaluating directional companion combat pocket synergies.
 * Canonical maximum Euclidean distance constraint strictly 200.0 uu.
 * (PRS-001-SRC-CDTC-002)
 */
USTRUCT(BlueprintType)
struct FAshenSpatialSynergyQuery
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Spatial")
	TObjectPtr<AActor> SourcePlayer = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Spatial")
	TObjectPtr<AActor> CompanionAlly = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Spatial")
	TObjectPtr<AActor> TargetEnemy = nullptr;

	/** Canonical maximum Euclidean distance constraint (Strictly 200.0 uu) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Spatial")
	float MaxSynergyDistanceUU = 200.0f;

	/** Canonical rear flank half-angle threshold (45.0 degrees = 90-degree total rear arc) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Spatial")
	float RequiredFlankHalfAngleDegrees = 45.0f;
};

/**
 * FAshenSpatialPredicateResult
 *
 * Per-predicate breakdown for companion synergy validation.
 */
USTRUCT(BlueprintType)
struct FAshenSpatialPredicateResult
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Spatial")
	bool bDistanceValid = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Spatial")
	bool bAngularFlankValid = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Spatial")
	bool bLineOfSightValid = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Spatial")
	bool bNavigationReachable = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Spatial")
	float ComputedFlankDot = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Spatial")
	float ActualDistanceUU = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Spatial")
	bool bOverallSynergyValid = false;
};
