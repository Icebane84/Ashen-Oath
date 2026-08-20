// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenBehemothKnockdownInterceptionEvaluator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBehemothKnockdownEvaluatedSignature, float, RemainingPoise, bool, bKnockdownNegated);

/**
 * UAshenBehemothKnockdownInterceptionEvaluator
 *
 * Evaluator validating Half-Sword Brace stance effectiveness against titan/behemoth-class knockdowns (PRS-001 Combat Blueprint).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenBehemothKnockdownInterceptionEvaluator : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|AegisBehemoth")
	bool EvaluateBehemothKnockdownInterception(float IncomingImpulse, float ActiveStamina);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|AegisBehemoth|Events")
	FOnBehemothKnockdownEvaluatedSignature OnBehemothKnockdownEvaluated;
};
