// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "AshenOchsCrownCounterBindGASAbility.generated.h"

/**
 * UAshenOchsCrownCounterBindGASAbility
 * 
 * Ochs Guard Execution: High eye-level crossguard bind with +0.12s parry window, executing an instant golden counter-bind riposte on deflection.
 */
UCLASS()
class ASHENOATH_API UAshenOchsCrownCounterBindGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenOchsCrownCounterBindGASAbility();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;

	virtual void EndAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		bool bReplicateEndAbility,
		bool bWasCancelled) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Oathbringer")
	float CounterBindRiposteBonus = 0.35f;
};
