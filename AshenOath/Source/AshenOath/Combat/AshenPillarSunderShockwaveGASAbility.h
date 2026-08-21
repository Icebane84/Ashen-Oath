// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenPillarSunderShockwaveGASAbility.generated.h"

/**
 * UAshenPillarSunderShockwaveGASAbility
 * 
 * Phase 2 transition ability: Boss sunders central pillars, fracturing geometry
 * and creating arena-wide debris shockwaves.
 */
UCLASS()
class ASHENOATH_API UAshenPillarSunderShockwaveGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenPillarSunderShockwaveGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Boss|Chaos")
	float ShockwaveRadiusUU = 1200.0f;
};
