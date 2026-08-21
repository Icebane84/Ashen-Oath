// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario4WhisperwoodTypes.h"
#include "AshenGroundingCheckGASAbility.generated.h"

/**
 * UAshenGroundingCheckGASAbility
 * 
 * Gameplay Ability executing Kaelen's reality grounding check against Garrett's skeletal gaze.
 */
UCLASS()
class ASHENOATH_API UAshenGroundingCheckGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGroundingCheckGASAbility();

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
	float MaxGroundingConeDegrees = 35.0f;
};
