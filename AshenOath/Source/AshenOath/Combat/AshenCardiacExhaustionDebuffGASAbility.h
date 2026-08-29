// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenCombatKinematicsTypes.h"
#include "AshenCardiacExhaustionDebuffGASAbility.generated.h"

/**
 * UAshenCardiacExhaustionDebuffGASAbility
 * 
 * Debuff state triggered when stamina falls below 35%: slows weapon swings by +25% and widens parry recovery frames by +30%.
 */
UCLASS()
class ASHENOATH_API UAshenCardiacExhaustionDebuffGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenCardiacExhaustionDebuffGASAbility();

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
	float SwingSlowdownPercent = 0.25f;
};
