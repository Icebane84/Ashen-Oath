// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Crafting/AshenRunicReliquaryTypes.h"
#include "AshenMemoryCrystallizationGASAbility.generated.h"

/**
 * UAshenMemoryCrystallizationGASAbility
 * 
 * Gameplay Ability transmuting emotional integration debt into a hilt relic.
 */
UCLASS()
class ASHENOATH_API UAshenMemoryCrystallizationGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenMemoryCrystallizationGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Reliquary")
	float CleansedDebtAmount = 0.50f;
};
