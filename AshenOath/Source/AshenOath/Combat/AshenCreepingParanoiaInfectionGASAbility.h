// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenShroudKnightTypes.h"
#include "AshenCreepingParanoiaInfectionGASAbility.generated.h"

/**
 * UAshenCreepingParanoiaInfectionGASAbility
 * 
 * Boss attack: Inflicts Creeping Paranoia directly on Kaelen, increasing infection by +25% and triggering sensory distortion.
 */
UCLASS()
class ASHENOATH_API UAshenCreepingParanoiaInfectionGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenCreepingParanoiaInfectionGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Paranoia")
	float ParanoiaInfectionDelta = 0.25f;
};
