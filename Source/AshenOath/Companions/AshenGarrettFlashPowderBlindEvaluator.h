// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenGarrettFlashPowderBlindEvaluator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFlashPowderBlindEvaluatedSignature, float, BlindDurationSeconds, float, AccuracyPenaltyPercent);

/**
 * UAshenGarrettFlashPowderBlindEvaluator
 *
 * Evaluator computing blind duration and accuracy penalties on blinded enemies (PRS-001 Garrett Slice).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenGarrettFlashPowderBlindEvaluator : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|GarrettFlashPowder")
	float EvaluateFlashPowderBlindImpact(float DistanceFromExplosion, float EnemyPerceptionScore);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|GarrettFlashPowder|Events")
	FOnFlashPowderBlindEvaluatedSignature OnBlindEvaluated;
};
