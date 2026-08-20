// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenOathbringerResonanceSynergyCalculator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnOathbringerResonanceSynergyCalculatedSignature, float, ActiveResonancePercent, float, PartyDamageBuffPercent);

/**
 * UAshenOathbringerResonanceSynergyCalculator
 *
 * Calculator computing party damage buffs when Oathbringer reaches max resonance (PRS-001 Oathbringer Slice).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenOathbringerResonanceSynergyCalculator : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|ResonanceSynergy")
	float CalculateResonancePartyBuff(float ResonancePercent);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ResonanceSynergy|Events")
	FOnOathbringerResonanceSynergyCalculatedSignature OnSynergyCalculated;
};
