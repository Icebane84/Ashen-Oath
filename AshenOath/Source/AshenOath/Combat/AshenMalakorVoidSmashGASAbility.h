// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario1CauterizedHeartTypes.h"
#include "AshenMalakorVoidSmashGASAbility.generated.h"

/**
 * UAshenMalakorVoidSmashGASAbility
 * 
 * Gameplay Ability executing Brother Malakor's heavy ritual-breaking Void Smash.
 */
UCLASS()
class ASHENOATH_API UAshenMalakorVoidSmashGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenMalakorVoidSmashGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Scenario1|GAS")
	float BaseDamage = 180.0f;
};
