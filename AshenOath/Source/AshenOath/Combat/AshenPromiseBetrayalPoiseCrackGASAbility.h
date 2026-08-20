// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenPromiseBetrayalPoiseCrackGASAbility.generated.h"

/**
 * UAshenPromiseBetrayalPoiseCrackGASAbility
 * 
 * Severe internal friction debuff triggered when a sacred promise is betrayed:
 * - Instantly cracks poise to 0.0
 * - Locks active light ability casting for 3.0 seconds
 */
UCLASS()
class ASHENOATH_API UAshenPromiseBetrayalPoiseCrackGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenPromiseBetrayalPoiseCrackGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Vow")
	float StaggerDurationSeconds = 3.0f;
};
