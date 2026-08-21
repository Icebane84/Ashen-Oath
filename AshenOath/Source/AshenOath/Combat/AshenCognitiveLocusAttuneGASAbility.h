// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario4WhisperwoodTypes.h"
#include "AshenCognitiveLocusAttuneGASAbility.generated.h"

/**
 * UAshenCognitiveLocusAttuneGASAbility
 * 
 * Gameplay Ability attuning to a discovered cognitive locus to anchor sanity.
 */
UCLASS()
class ASHENOATH_API UAshenCognitiveLocusAttuneGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenCognitiveLocusAttuneGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Scenario4|GAS")
	float SanityRestored = 0.20f;
};
