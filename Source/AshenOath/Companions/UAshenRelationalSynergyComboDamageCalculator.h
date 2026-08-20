// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UAshenRelationalSynergyComboDamageCalculator.generated.h"

/**
 * UAshenRelationalSynergyComboDamageCalculator
 * Calculates joint companion synergy attack damage bonuses.
 */
UCLASS()
class ASHENOATH_API UAshenRelationalSynergyComboDamageCalculator : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	static float CalculateComboDamageMultiplier(float GarrettTrust, float SerafinaTrust, float KaelenResolve);
};
