// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UAshenRelationalTrustAtrophyOverTimeCalculator.generated.h"

/**
 * UAshenRelationalTrustAtrophyOverTimeCalculator
 * Calculates passive trust decay during extended companion separation.
 */
UCLASS()
class ASHENOATH_API UAshenRelationalTrustAtrophyOverTimeCalculator : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	static float CalculateAtrophiedTrust(float InitialTrust, float SeparationHours);
};
