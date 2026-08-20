// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenHermeneuticFragmentationCalculator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFragmentationCalculatedSignature, float, HermeneuticFragmentationPercent, bool, bIsDissonanceThresholdExceeded);

/**
 * UAshenHermeneuticFragmentationCalculator
 *
 * Calculator computing fragmentation levels when memory anchors conflict (UMB-INT-001 Memory Slice).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenHermeneuticFragmentationCalculator : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|HermeneuticFragmentation")
	float CalculateFragmentation(float DissonantNodeCount, float ActiveSpiritualStain);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|HermeneuticFragmentation|Events")
	FOnFragmentationCalculatedSignature OnFragmentationCalculated;
};
