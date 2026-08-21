// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Narrative/AshenCampfireHearthTypes.h"
#include "AshenSolemnVigilRestGASAbility.generated.h"

/**
 * UAshenSolemnVigilRestGASAbility
 * 
 * Executes solemn vigil rest at the campfire, purging acute dysregulation
 * and granting deep emotional grounding.
 */
UCLASS()
class ASHENOATH_API UAshenSolemnVigilRestGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSolemnVigilRestGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Hearth")
	float DysregulationCleansedPercent = 1.0f; // 100%
};
