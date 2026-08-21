// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario1CauterizedHeartTypes.h"
#include "AshenKaelenClarityOfHeartGASAbility.generated.h"

/**
 * UAshenKaelenClarityOfHeartGASAbility
 * 
 * Channeling ability executing the Clarity of Heart ritual at the chapel altar.
 */
UCLASS()
class ASHENOATH_API UAshenKaelenClarityOfHeartGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenKaelenClarityOfHeartGASAbility();

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
	float ChannelDurationSeconds = 10.0f;
};
