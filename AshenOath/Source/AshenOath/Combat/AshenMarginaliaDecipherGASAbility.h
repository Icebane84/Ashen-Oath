// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Narrative/AshenJournalTypes.h"
#include "AshenMarginaliaDecipherGASAbility.generated.h"

/**
 * UAshenMarginaliaDecipherGASAbility
 * 
 * Lore deciphering ability in the Campfire Journal that grants the party the "Studied Adversary" (+5% damage) passive buff.
 */
UCLASS()
class ASHENOATH_API UAshenMarginaliaDecipherGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenMarginaliaDecipherGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Lore")
	float StudiedAdversaryDamageBonusPercent = 0.05f;
};
