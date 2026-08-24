// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenChaosNavmeshTypes.h"
#include "AshenDebrisWallSlamGASAbility.generated.h"

/**
 * UAshenDebrisWallSlamGASAbility
 * 
 * Slams an enemy into dynamic fractured rubble, dealing +50% crushing damage and applying a 2.0s poise break.
 */
UCLASS()
class ASHENOATH_API UAshenDebrisWallSlamGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenDebrisWallSlamGASAbility();

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
	float CrushingDamageBonusMultiplier = 1.50f;
};
