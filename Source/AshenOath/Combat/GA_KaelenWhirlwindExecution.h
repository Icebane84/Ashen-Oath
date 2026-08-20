// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenWhirlwindExecution.generated.h"

/**
 * UGA_KaelenWhirlwindExecution
 *
 * Kaelen's heavy GAS whirlwind finisher dealing 600 Physical damage in a 360-degree 400u sweep.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenWhirlwindExecution : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenWhirlwindExecution();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|WhirlwindExecution")
	float Damage = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|WhirlwindExecution")
	float SweepRadius = 400.0f;
};
