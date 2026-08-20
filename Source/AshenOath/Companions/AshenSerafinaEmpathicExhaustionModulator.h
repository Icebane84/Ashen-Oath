// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenSerafinaEmpathicExhaustionModulator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEmpathicExhaustionModulatedSignature, float, EffectiveHealingOutput, bool, bIsExhaustionThresholdExceeded);

/**
 * UAshenSerafinaEmpathicExhaustionModulator
 *
 * Modulator adjusting Serafina's healing efficiency based on Kaelen's Spiritual Stain level (can-empathic_burnout, PRS-001 Combat Blueprint).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenSerafinaEmpathicExhaustionModulator : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|EmpathicExhaustion")
	float ModulateSerafinaHealingOutput(float BaseHealing, float KaelenStainPercent);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|EmpathicExhaustion|Events")
	FOnEmpathicExhaustionModulatedSignature OnExhaustionModulated;
};
