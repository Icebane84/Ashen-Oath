// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "AshenMMC_QuietGrace.generated.h"

/**
 * UAshenMMC_QuietGrace
 *
 * Modifier Magnitude Calculation scaling Serafina's passive empathic damage mitigation ("Quiet Grace").
 * Filters raw transferred pain based on Serafina's EmpathyResonance attribute set.
 */
UCLASS()
class ASHENOATH_API UAshenMMC_QuietGrace : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
	UAshenMMC_QuietGrace();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
};
