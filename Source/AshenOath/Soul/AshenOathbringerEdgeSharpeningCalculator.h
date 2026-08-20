// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOathbringerEdgeSharpeningCalculator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEdgeSharpeningCalculatedSignature, int32, SharpeningTier, float, PhysicalDamageMultiplier);

/**
 * UAshenOathbringerEdgeSharpeningCalculator
 *
 * Subsystem computing physical damage multipliers based on weapon sharpening tier (PRS-001 Oathbringer Slice).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathbringerEdgeSharpeningCalculator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOathbringerEdgeSharpeningCalculator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|EdgeSharpening")
	float CalculatePhysicalDamageMultiplier(int32 SharpeningTier);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|EdgeSharpening|Events")
	FOnEdgeSharpeningCalculatedSignature OnSharpeningCalculated;
};
