// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenSanctuaryKineticCleaveGASAbility.generated.h"

/**
 * UAshenSanctuaryKineticCleaveGASAbility
 * 
 * Boss Phase 1 kinetic cleave attack with wide frontal arc and high poise strain.
 */
UCLASS()
class ASHENOATH_API UAshenSanctuaryKineticCleaveGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSanctuaryKineticCleaveGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Boss|Combat")
	float CleaveArcDegrees = 160.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Boss|Combat")
	float PoiseDamageScalar = 2.5f;
};
