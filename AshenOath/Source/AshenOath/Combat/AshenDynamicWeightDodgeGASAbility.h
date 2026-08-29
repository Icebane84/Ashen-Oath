// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenCombatKinematicsTypes.h"
#include "AshenDynamicWeightDodgeGASAbility.generated.h"

/**
 * UAshenDynamicWeightDodgeGASAbility
 * 
 * Executes weight-scaled dodge roll kinematics (0.32s ninja roll vs 0.55s heavy fat roll) with dynamic i-frames and stamina consumption.
 */
UCLASS()
class ASHENOATH_API UAshenDynamicWeightDodgeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenDynamicWeightDodgeGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Kinematics")
	EAshenWeightClass ActiveWeightClass = EAshenWeightClass::MediumLoad;
};
