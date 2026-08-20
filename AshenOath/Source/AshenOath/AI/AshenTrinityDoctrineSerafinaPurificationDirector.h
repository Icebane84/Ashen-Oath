// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenTrinityDoctrineSerafinaPurificationDirector.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSerafinaPurificationEvaluatedSignature, float, InstantStaminaRestored, bool, bHarmonicFlowActive);

/**
 * UAshenTrinityDoctrineSerafinaPurificationDirector
 *
 * AI Director executing Serafina's High-Trust Harmonic Purification Flow (instant stamina restore on parry) vs Low-Trust Healing Throttle (PRS-001 Combat Blueprint V5.0 Trinity Doctrine).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenTrinityDoctrineSerafinaPurificationDirector : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|TrinitySerafina")
	float EvaluateSerafinaParryPurificationFlow(float SerafinaTrustLevel);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|TrinitySerafina|Events")
	FOnSerafinaPurificationEvaluatedSignature OnPurificationEvaluated;
};
