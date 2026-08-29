// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenDestructionWeatherAITypes.h"
#include "AshenDestructionPincerFlankGASAbility.generated.h"

/**
 * UAshenDestructionPincerFlankGASAbility
 * 
 * Executed by AI skirmishers navigating around cleaved rubble obstacles: executes an accelerated +65 deg flanking sprint to encircle player targets.
 */
UCLASS()
class ASHENOATH_API UAshenDestructionPincerFlankGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenDestructionPincerFlankGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Convergence")
	float FlankSpeedMultiplier = 1.35f;
};
