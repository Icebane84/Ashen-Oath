// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario5WeepingMireTypes.h"
#include "AshenActivateUnchainedModeGASAbility.generated.h"

/**
 * UAshenActivateUnchainedModeGASAbility
 * 
 * Gameplay Ability breaking mortal constraints to enter Unchained Frenzy (+50% damage).
 */
UCLASS()
class ASHENOATH_API UAshenActivateUnchainedModeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenActivateUnchainedModeGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Scenario5|GAS")
	float FrenzyDurationSeconds = 12.0f;
};
