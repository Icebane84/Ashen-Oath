// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenChaosNavmeshTypes.h"
#include "AshenStructuralCollapseStumbleGASAbility.generated.h"

/**
 * UAshenStructuralCollapseStumbleGASAbility
 * 
 * Applies physics knockback and stumble recovery when a character is within an active structural collapse zone.
 */
UCLASS()
class ASHENOATH_API UAshenStructuralCollapseStumbleGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenStructuralCollapseStumbleGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Chaos")
	float StumbleDurationSeconds = 1.2f;
};
