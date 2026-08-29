// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenDestructionWeatherAITypes.h"
#include "AshenCoverShatterShrapnelGASAbility.generated.h"

/**
 * UAshenCoverShatterShrapnelGASAbility
 * 
 * Environmental Shrapnel Detonation: Triggers 250 kinetic damage and +40 poise break to all units cowering within 250uu of collapsing stone cover.
 */
UCLASS()
class ASHENOATH_API UAshenCoverShatterShrapnelGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenCoverShatterShrapnelGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Convergence")
	float ShrapnelDamage = 250.0f;
};
