// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenUnbrokenTripartiteAegisGASAbility.generated.h"

/**
 * UAshenUnbrokenTripartiteAegisGASAbility
 * 
 * Defensive party ward active during Tripartite resonance:
 * - Grants +20% damage mitigation
 * - Grants hit-stagger immunity to all 3 party members
 */
UCLASS()
class ASHENOATH_API UAshenUnbrokenTripartiteAegisGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenUnbrokenTripartiteAegisGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Trio")
	float DamageMitigationPercent = 20.0f;
};
