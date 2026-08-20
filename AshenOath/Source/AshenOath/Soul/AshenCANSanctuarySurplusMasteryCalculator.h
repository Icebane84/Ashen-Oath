// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenCANSanctuarySurplusMasteryCalculator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSanctuarySurplusMasteryCalculatedSignature, int32, BonusSurplusResources, float, Multiplier);

/**
 * UAshenCANSanctuarySurplusMasteryCalculator
 *
 * Calculator computing sanctuary resource generation boosts based on Serafina's empathic health (PRS-001 Serafina Slice).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenCANSanctuarySurplusMasteryCalculator : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SanctuarySurplus")
	int32 CalculateSanctuarySurplusBonus(int32 BaseResources, float SerafinaEmpathicHealthPercent);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SanctuarySurplus|Events")
	FOnSanctuarySurplusMasteryCalculatedSignature OnSurplusCalculated;
};
