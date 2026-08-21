// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Archive/AshenCodexArchiveTypes.h"
#include "AshenTriggerMemoryVignetteGASAbility.generated.h"

/**
 * UAshenTriggerMemoryVignetteGASAbility
 * 
 * Gameplay Ability initiating a flashback vignette cutscene upon examining key relics.
 */
UCLASS()
class ASHENOATH_API UAshenTriggerMemoryVignetteGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenTriggerMemoryVignetteGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Archive")
	FName TargetVignetteId = NAME_None;
};
