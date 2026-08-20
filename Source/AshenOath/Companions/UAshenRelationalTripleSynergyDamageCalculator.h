// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UAshenRelationalTripleSynergyDamageCalculator.generated.h"

/**
 * UAshenRelationalTripleSynergyDamageCalculator
 * Calculates 3-party combo damage multipliers based on Garrett Trust & Serafina Trust.
 */
UCLASS()
class ASHENOATH_API UAshenRelationalTripleSynergyDamageCalculator : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "AshenOath|Companion")
	static float CalculateTripleSynergyMultiplier(float GarrettTrust, float SerafinaTrust, float Resolve);
};
