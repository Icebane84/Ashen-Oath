// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenCompanionPinningExecutionGASAbility.generated.h"

/**
 * UAshenCompanionPinningExecutionGASAbility
 * 
 * Boss ability targeting a companion for a lethal pinning strike, initiating
 * the 3.0s intervention window.
 */
UCLASS()
class ASHENOATH_API UAshenCompanionPinningExecutionGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenCompanionPinningExecutionGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Boss|Crisis")
	float DecisionWindowSeconds = 3.0f;
};
