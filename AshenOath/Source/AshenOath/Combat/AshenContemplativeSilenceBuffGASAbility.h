// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Narrative/AshenJournalTypes.h"
#include "AshenContemplativeSilenceBuffGASAbility.generated.h"

/**
 * UAshenContemplativeSilenceBuffGASAbility
 * 
 * Contemplative silence buff granting +15% poise recovery to all companions at the campfire.
 */
UCLASS()
class ASHENOATH_API UAshenContemplativeSilenceBuffGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenContemplativeSilenceBuffGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Campfire")
	float PoiseRecoveryBonusPercent = 0.15f;
};
