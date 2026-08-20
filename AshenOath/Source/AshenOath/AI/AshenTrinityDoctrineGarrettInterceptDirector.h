// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenTrinityDoctrineGarrettInterceptDirector.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGarrettInterceptEvaluatedSignature, FVector, TargetInterceptLocation, bool, bIsInterceptActive);

/**
 * UAshenTrinityDoctrineGarrettInterceptDirector
 *
 * AI Director executing Garrett's High-Trust Rear Arc Intercept vs Low-Trust Hesitation (PRS-001 Combat Blueprint V5.0 Trinity Doctrine).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenTrinityDoctrineGarrettInterceptDirector : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|TrinityGarrett")
	FVector EvaluateGarrettInterceptPosition(FVector KaelenLocation, FVector RearBlindSpotDirection, float GarrettTrustLevel);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|TrinityGarrett|Events")
	FOnGarrettInterceptEvaluatedSignature OnGarrettInterceptEvaluated;
};
