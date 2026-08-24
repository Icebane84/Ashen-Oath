// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario8Types.h"
#include "AshenPitchBlackBlindnessDebuffGASAbility.generated.h"

/**
 * UAshenPitchBlackBlindnessDebuffGASAbility
 * 
 * Applies 60% attack miss penalty, disables soft lock-on, and scales somatic fear in total darkness.
 */
UCLASS()
class ASHENOATH_API UAshenPitchBlackBlindnessDebuffGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenPitchBlackBlindnessDebuffGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Darkness")
	float MaxDarknessMissPenalty = 0.60f;
};
