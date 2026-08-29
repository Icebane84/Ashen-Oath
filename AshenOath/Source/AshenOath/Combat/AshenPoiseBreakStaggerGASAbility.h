// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenCombatKinematicsTypes.h"
#include "AshenPoiseBreakStaggerGASAbility.generated.h"

/**
 * UAshenPoiseBreakStaggerGASAbility
 * 
 * Executes the shattered guard posture state, applying a 0.20s global hitstop time dilation (0.02x) and opening the +50% critical riposte window.
 */
UCLASS()
class ASHENOATH_API UAshenPoiseBreakStaggerGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenPoiseBreakStaggerGASAbility();

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
	float HitstopTimeDilation = 0.02f;
};
