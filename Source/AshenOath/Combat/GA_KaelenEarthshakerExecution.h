// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenEarthshakerExecution.generated.h"

/**
 * UGA_KaelenEarthshakerExecution
 *
 * Kaelen's heavy GAS execution slam dealing 700 Physical damage and fracturing ground in a 500u radius.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenEarthshakerExecution : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenEarthshakerExecution();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|EarthshakerExecution")
	float Damage = 700.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|EarthshakerExecution")
	float Radius = 500.0f;
};
