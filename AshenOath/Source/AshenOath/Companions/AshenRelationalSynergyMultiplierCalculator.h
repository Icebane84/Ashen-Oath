// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenRelationalSynergyMultiplierCalculator.generated.h"

/**
 * UAshenRelationalSynergyMultiplierCalculator
 * Calculates overall companion synergy multiplier for party-wide stat buffs.
 */
UCLASS()
class ASHENOATH_API UAshenRelationalSynergyMultiplierCalculator : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	static float CalculatePartySynergyMultiplier(float GarrettTrust, float SerafinaTrust);
};
