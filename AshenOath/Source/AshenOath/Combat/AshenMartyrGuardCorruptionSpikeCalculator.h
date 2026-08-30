// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenMartyrGuardCorruptionSpikeCalculator.generated.h"

class UAshenSoulPublisher;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCorruptionSpikeCalculatedSignature, float, CorruptionSpikeAmount, float, NewTotalCorruption);

/**
 * UAshenMartyrGuardCorruptionSpikeCalculator
 *
 * Computes normalized corruption spikes ([0.0, 1.0]) when Kaelen intercepts
 * lethal attacks aimed at companions, committing deltas directly to UAshenSoulPublisher.
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenMartyrGuardCorruptionSpikeCalculator : public UObject
{
	GENERATED_BODY()

public:
	/** Computes normalized corruption spike and commits to UAshenSoulPublisher */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|MartyrGuardCorruption")
	float CalculateMartyrCorruptionSpike(float InterceptedLethalDamage, float LegacyUnusedCorruption = 0.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MartyrGuardCorruption|Events")
	FOnCorruptionSpikeCalculatedSignature OnCorruptionSpikeCalculated;

private:
	UAshenSoulPublisher* GetSoulPublisher() const;
};
