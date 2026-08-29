// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenAlchemicalSlagTypes.h"
#include "AshenConflagrationSlagBurstGASAbility.generated.h"

/**
 * UAshenConflagrationSlagBurstGASAbility
 * 
 * Conflagration Deflagration: Consumes superheated soot (>=0.80) and Pyrophoric Naphtha to detonate a 450.0 Heat AoE blast across 400uu.
 */
UCLASS()
class ASHENOATH_API UAshenConflagrationSlagBurstGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenConflagrationSlagBurstGASAbility();

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
	float BlastDamage = 450.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|AlchemicalSlag")
	float BlastRadiusUU = 400.0f;
};
