// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenAlchemicalSlagTypes.h"
#include "AshenGalvanicLightningPullGASAbility.generated.h"

/**
 * UAshenGalvanicLightningPullGASAbility
 * 
 * Galvanic Pull Execution: Striking with Conductive Copper Salve in lightning weather acts as a live beacon, pulling down a 500.0 Shock damage lightning bolt.
 */
UCLASS()
class ASHENOATH_API UAshenGalvanicLightningPullGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGalvanicLightningPullGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|AlchemicalSlag")
	float LightningDamage = 500.0f;
};
