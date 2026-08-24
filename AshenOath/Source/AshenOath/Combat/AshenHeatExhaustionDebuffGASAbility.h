// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario7Types.h"
#include "AshenHeatExhaustionDebuffGASAbility.generated.h"

/**
 * UAshenHeatExhaustionDebuffGASAbility
 * 
 * Applies stamina drain multiplier scaling (1.0x to 2.0x) and thermal screen blur when heatstroke occurs.
 */
UCLASS()
class ASHENOATH_API UAshenHeatExhaustionDebuffGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenHeatExhaustionDebuffGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Heat")
	float MaxStaminaDrainMultiplier = 2.0f;
};
