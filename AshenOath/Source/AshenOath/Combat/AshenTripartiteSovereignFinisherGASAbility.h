// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario10Types.h"
#include "AshenTripartiteSovereignFinisherGASAbility.generated.h"

/**
 * UAshenTripartiteSovereignFinisherGASAbility
 * 
 * Grand Zenith 3-way synchronized finisher executing Kaelen, Garrett, and Serafina's combined kinetic combo (4.0x damage, 0.10x dilation).
 */
UCLASS()
class ASHENOATH_API UAshenTripartiteSovereignFinisherGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenTripartiteSovereignFinisherGASAbility();

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
	float FinisherDamageMultiplier = 4.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Zenith")
	float TimeDilationScale = 0.10f;
};
