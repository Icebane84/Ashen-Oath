// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenChaosNavmeshTypes.h"
#include "AshenSunderDebrisClearingGASAbility.generated.h"

/**
 * UAshenSunderDebrisClearingGASAbility
 * 
 * Heavy greatsword kinetic cleave that disintegrates obstructive rubble and restores the navmesh.
 */
UCLASS()
class ASHENOATH_API UAshenSunderDebrisClearingGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSunderDebrisClearingGASAbility();

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
	float PulverizeRadiusUU = 300.0f;
};
