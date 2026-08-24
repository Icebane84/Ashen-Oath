// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Narrative/AshenJournalTypes.h"
#include "AshenCampfireContemplationGASAbility.generated.h"

/**
 * UAshenCampfireContemplationGASAbility
 * 
 * Campfire rest ability restoring party sanity (+25%) and refreshing weapon durability.
 */
UCLASS()
class ASHENOATH_API UAshenCampfireContemplationGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenCampfireContemplationGASAbility();

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
	float SanityRestoredPercentage = 0.25f;
};
