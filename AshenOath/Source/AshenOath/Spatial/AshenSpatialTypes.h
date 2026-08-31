// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "AshenSpatialTypes.generated.h"

/**
 * FAshenSpatialConvexHullQuery
 *
 * Query parameters for evaluating directional companion combat pocket synergies.
 * (PRS-001-CDTC-001)
 */
USTRUCT(BlueprintType)
struct FAshenSpatialConvexHullQuery
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|SpatialAI")
	TObjectPtr<AActor> SourcePlayer = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|SpatialAI")
	TObjectPtr<AActor> CompanionAlly = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|SpatialAI")
	TObjectPtr<AActor> TargetEnemy = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|SpatialAI")
	float MaxDistanceEnvelope = 250.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|SpatialAI")
	float RequiredFlankAngleDegrees = 45.0f;
};
