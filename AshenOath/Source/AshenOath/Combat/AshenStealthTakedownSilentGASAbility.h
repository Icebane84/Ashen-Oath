// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario2SentinelsGambitTypes.h"
#include "AshenStealthTakedownSilentGASAbility.generated.h"

/**
 * UAshenStealthTakedownSilentGASAbility
 * 
 * Gameplay Ability executing a synchronized silent garrote takedown from behind patrols.
 */
UCLASS()
class ASHENOATH_API UAshenStealthTakedownSilentGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenStealthTakedownSilentGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Scenario2|GAS")
	float TrustReward = 0.15f;
};
