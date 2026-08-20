// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AshenRelationalTrustAtrophyCalculator.generated.h"

/**
 * UAshenRelationalTrustAtrophyCalculator
 * Calculates relational trust decay when companion advice is repeatedly ignored.
 */
UCLASS()
class ASHENOATH_API UAshenRelationalTrustAtrophyCalculator : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "AshenOath|Companions")
	static float CalculateTrustAtrophy(float CurrentTrust, int32 IgnoredAdviceCount);
};
