// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario4WhisperwoodTypes.h"
#include "AshenWhisperingWindsGustGASAbility.generated.h"

/**
 * UAshenWhisperingWindsGustGASAbility
 * 
 * Environmental ability triggering sudden gusts of purple mist and auditory whispers.
 */
UCLASS()
class ASHENOATH_API UAshenWhisperingWindsGustGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenWhisperingWindsGustGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Scenario4|GAS")
	float MistDensityIncrease = 0.25f;
};
