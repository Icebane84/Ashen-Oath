// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UAshenRelationalTrustLevelThresholdCalculator.generated.h"

/**
 * UAshenRelationalTrustLevelThresholdCalculator
 * Calculates threshold levels for unlocking companion synergy abilities.
 */
UCLASS()
class ASHENOATH_API UAshenRelationalTrustLevelThresholdCalculator : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	static int32 CalculateTrustTier(float TrustValue);
};
