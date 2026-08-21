// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenTraumaTransmutationSurgeGASAbility.generated.h"

/**
 * UAshenTraumaTransmutationSurgeGASAbility
 * 
 * Applies permanent stat passives derived from processed trauma debt.
 */
UCLASS()
class ASHENOATH_API UAshenTraumaTransmutationSurgeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenTraumaTransmutationSurgeGASAbility();

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

	/** Applies the trait bonus to the character */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Hearth")
	bool ApplyTransmutedBonus(float BonusScalar);
};
