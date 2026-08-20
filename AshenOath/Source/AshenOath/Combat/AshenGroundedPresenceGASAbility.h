// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenGroundedPresenceGASAbility.generated.h"

/**
 * UAshenGroundedPresenceGASAbility
 * 
 * Companion passive presence ability granting +0.05 Resolve regen per second
 * during harmonious, silent accompaniment.
 */
UCLASS()
class ASHENOATH_API UAshenGroundedPresenceGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGroundedPresenceGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Presence")
	float ResolveRegenPerSecond = 0.05f;
};
