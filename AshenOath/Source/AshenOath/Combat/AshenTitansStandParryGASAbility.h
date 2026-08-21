// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario1CauterizedHeartTypes.h"
#include "AshenTitansStandParryGASAbility.generated.h"

/**
 * UAshenTitansStandParryGASAbility
 * 
 * Gameplay Ability executing Kaelen's heavy Titan's Stand parry with maximum DualSense trigger resistance.
 */
UCLASS()
class ASHENOATH_API UAshenTitansStandParryGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenTitansStandParryGASAbility();

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
	float ParryWindowSeconds = 0.40f;
};
