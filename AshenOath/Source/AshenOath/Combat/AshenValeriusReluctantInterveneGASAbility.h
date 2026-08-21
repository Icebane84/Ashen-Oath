// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario1CauterizedHeartTypes.h"
#include "AshenValeriusReluctantInterveneGASAbility.generated.h"

/**
 * UAshenValeriusReluctantInterveneGASAbility
 * 
 * Gameplay Ability executing Valerius's intervention parry against Malakor's hammer.
 */
UCLASS()
class ASHENOATH_API UAshenValeriusReluctantInterveneGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenValeriusReluctantInterveneGASAbility();

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
	float ExhaustionRecoveryFrames = 45.0f;
};
