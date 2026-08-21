// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Tactics/AshenSquadTacticalTypes.h"
#include "AshenSynchronizedFlankStrikeGASAbility.generated.h"

/**
 * UAshenSynchronizedFlankStrikeGASAbility
 * 
 * Gameplay Ability executing a synchronized strike between Kaelen and companion.
 */
UCLASS()
class ASHENOATH_API UAshenSynchronizedFlankStrikeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSynchronizedFlankStrikeGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Tactics")
	float BaseComboDamage = 350.0f;
};
