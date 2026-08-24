// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Narrative/AshenJournalTypes.h"
#include "AshenSootPurgeCleansingGASAbility.generated.h"

/**
 * UAshenSootPurgeCleansingGASAbility
 * 
 * Cleanses and burnishes weapon soot layer at the campfire restoring weapon sheen and edge sharpness.
 */
UCLASS()
class ASHENOATH_API UAshenSootPurgeCleansingGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSootPurgeCleansingGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Soot")
	float SootRemovedMicrons = 25.0f;
};
