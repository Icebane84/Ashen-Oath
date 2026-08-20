// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenPromiseBondStealtheadAuraGASAbility.generated.h"

/**
 * UAshenPromiseBondStealtheadAuraGASAbility
 * 
 * Passive trio aura granting +15% incoming damage mitigation when active
 * canonical promises are unbroken and resonance is attuned.
 */
UCLASS()
class ASHENOATH_API UAshenPromiseBondStealtheadAuraGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenPromiseBondStealtheadAuraGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Aura")
	float DamageMitigationScalar = 0.15f;
};
