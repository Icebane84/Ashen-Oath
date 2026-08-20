// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_BossAbominationVoidSmashExecution.generated.h"

/**
 * UGA_BossAbominationVoidSmashExecution
 *
 * Boss GAS ability executing a 900 Void damage slam fracturing arena terrain in a 700u radius.
 */
UCLASS()
class ASHENOATH_API UGA_BossAbominationVoidSmashExecution : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_BossAbominationVoidSmashExecution();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|VoidSmashExecution")
	float Damage = 900.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|VoidSmashExecution")
	float Radius = 700.0f;
};
