// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenGarrettFlankEQSEvaluator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGarrettEQSFlankScoreEvaluatedSignature, FVector, OptimalFlankPosition, float, PriorityScore);

/**
 * UAshenGarrettFlankEQSEvaluator
 *
 * Evaluator updating Garrett's Environmental Query System to prioritize Kaelen's blind spots under Unbroken (PRS-001 Combat Blueprint).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenGarrettFlankEQSEvaluator : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|GarrettEQS")
	FVector EvaluateGarrettBlindSpotPosition(FVector KaelenLocation, FVector KaelenForwardVector, bool bIsKaelenUnbroken);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|GarrettEQS|Events")
	FOnGarrettEQSFlankScoreEvaluatedSignature OnEQSFlankScoreEvaluated;
};
