// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Tactics/AshenSquadTacticalTypes.h"
#include "AshenComboDischargeBurstGASAbility.generated.h"

/**
 * UAshenComboDischargeBurstGASAbility
 * 
 * Gameplay Ability discharging a 3-character synchronized finisher burst.
 */
UCLASS()
class ASHENOATH_API UAshenComboDischargeBurstGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenComboDischargeBurstGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Tactics")
	float BurstDamageMultiplier = 2.50f;
};
