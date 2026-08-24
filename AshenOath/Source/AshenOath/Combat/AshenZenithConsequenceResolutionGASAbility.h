// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario10Types.h"
#include "AshenZenithConsequenceResolutionGASAbility.generated.h"

/**
 * UAshenZenithConsequenceResolutionGASAbility
 * 
 * Climax ability unleashing the grand consequence blast wave across the apex altar and committing final world state.
 */
UCLASS()
class ASHENOATH_API UAshenZenithConsequenceResolutionGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenZenithConsequenceResolutionGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Zenith")
	float BlastWaveRadiusUU = 3500.0f;
};
