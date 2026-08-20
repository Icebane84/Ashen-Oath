// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenMartyrGuardCorruptionSpikeCalculator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCorruptionSpikeCalculatedSignature, float, CorruptionSpikeAmount, float, NewTotalCorruption);

/**
 * UAshenMartyrGuardCorruptionSpikeCalculator
 *
 * Calculator computing corruption spikes when Kaelen intercepts lethal attacks aimed at companions (PRS-001 Combat Blueprint).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenMartyrGuardCorruptionSpikeCalculator : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|MartyrGuardCorruption")
	float CalculateMartyrCorruptionSpike(float InterceptedLethalDamage, float CurrentCorruption);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MartyrGuardCorruption|Events")
	FOnCorruptionSpikeCalculatedSignature OnCorruptionSpikeCalculated;
};
