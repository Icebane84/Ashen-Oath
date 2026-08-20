// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenShadowRestraintGroundingGASAbility.generated.h"

/**
 * UAshenShadowRestraintGroundingGASAbility
 * 
 * Companion emergency grounding ability:
 * - Interrupts Kaelen's dark corruption overflow
 * - Purges runaway dysregulation spikes via physical restraint / psychic anchor
 */
UCLASS()
class ASHENOATH_API UAshenShadowRestraintGroundingGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenShadowRestraintGroundingGASAbility();

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

	/** Executes grounding purge on Kaelen */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Restraint")
	bool ExecuteGroundingPurge(AActor* KaelenActor);
};
