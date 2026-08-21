// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario2SentinelsGambitTypes.h"
#include "AshenRavineLureBaitGASAbility.generated.h"

/**
 * UAshenRavineLureBaitGASAbility
 * 
 * Gameplay Ability deploying a sonic distraction lure near the ravine edge to attract patrolling ghouls.
 */
UCLASS()
class ASHENOATH_API UAshenRavineLureBaitGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenRavineLureBaitGASAbility();

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
	float LureAttractionRadiusCentimeters = 1200.0f;
};
