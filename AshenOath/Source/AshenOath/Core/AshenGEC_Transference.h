// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "AshenGEC_Transference.generated.h"

/**
 * UAshenGEC_Transference
 *
 * Execution Calculation redirecting incoming damage from Kaelen/Garrett to Serafina.
 * Snapshots damage magnitude, filters through QuietGrace MMC mitigation,
 * applies transferred pain to Serafina, and clears direct damage on ally target to prevent double-dipping.
 */
UCLASS()
class ASHENOATH_API UAshenGEC_Transference : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:
	UAshenGEC_Transference();

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
