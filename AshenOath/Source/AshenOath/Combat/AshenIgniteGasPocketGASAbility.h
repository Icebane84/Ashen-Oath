// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario5WeepingMireTypes.h"
#include "AshenIgniteGasPocketGASAbility.generated.h"

/**
 * UAshenIgniteGasPocketGASAbility
 * 
 * Gameplay Ability igniting volatile methane pockets with White Flame for explosive AoE damage.
 */
UCLASS()
class ASHENOATH_API UAshenIgniteGasPocketGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenIgniteGasPocketGASAbility();

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
	float BlastDamage = 250.0f;
};
