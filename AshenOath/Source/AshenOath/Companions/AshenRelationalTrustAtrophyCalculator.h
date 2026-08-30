// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AshenRelationalTrustAtrophyCalculator.generated.h"

/**
 * UAshenRelationalTrustAtrophyCalculator
 * Calculates relational trust decay when companion advice is repeatedly ignored,
 * and atomically commits deltas to UAshenSoulPublisher SSoT.
 */
UCLASS()
class ASHENOATH_API UAshenRelationalTrustAtrophyCalculator : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "AshenOath|Companions")
	static float CalculateTrustAtrophy(float CurrentTrust, int32 IgnoredAdviceCount);

	/** Atomically applies trust decay to UAshenSoulPublisher */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions", meta = (WorldContext = "WorldContextObject"))
	static float ApplyTrustAtrophy(FName CompanionID, int32 IgnoredAdviceCount, const UObject* WorldContextObject);
};
