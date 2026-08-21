// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario4WhisperwoodTypes.h"
#include "AshenPhantomSlashDisperseGASAbility.generated.h"

/**
 * UAshenPhantomSlashDisperseGASAbility
 * 
 * Gameplay Ability executing a cleave attack through phantom entities, instantly dissolving them.
 */
UCLASS()
class ASHENOATH_API UAshenPhantomSlashDisperseGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenPhantomSlashDisperseGASAbility();

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
};
