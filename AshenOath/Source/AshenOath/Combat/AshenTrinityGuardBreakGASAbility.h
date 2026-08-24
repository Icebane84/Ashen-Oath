// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenShroudKnightTypes.h"
#include "AshenTrinityGuardBreakGASAbility.generated.h"

/**
 * UAshenTrinityGuardBreakGASAbility
 * 
 * Step 1 of Trinity Strike: Kaelen executes a heavy kinetic guard break, shattering the Shroud-Knight's physical poise.
 */
UCLASS()
class ASHENOATH_API UAshenTrinityGuardBreakGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenTrinityGuardBreakGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Trinity")
	float GuardBreakPoiseDamage = 500.0f;
};
