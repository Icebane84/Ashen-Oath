// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenRelationalTrustRecoveryCalculator.generated.h"

/**
 * UAshenRelationalTrustRecoveryCalculator
 * Calculates trust recovery when companion combat suggestions are followed.
 */
UCLASS()
class ASHENOATH_API UAshenRelationalTrustRecoveryCalculator : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	static float CalculateTrustRecovery(float CurrentTrust, float TacticalSynergyRating);
};
