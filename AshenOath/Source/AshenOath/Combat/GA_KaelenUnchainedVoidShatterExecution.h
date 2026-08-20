// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenUnchainedVoidShatterExecution.generated.h"

/**
 * UGA_KaelenUnchainedVoidShatterExecution
 *
 * Kaelen's unchained ultimate GAS execution dealing 1200 Void/Physical damage in a 600u shockwave.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenUnchainedVoidShatterExecution : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenUnchainedVoidShatterExecution();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|VoidShatterExecution")
	float Damage = 1200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|VoidShatterExecution")
	float Radius = 600.0f;
};
