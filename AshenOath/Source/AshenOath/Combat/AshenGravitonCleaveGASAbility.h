// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario9Types.h"
#include "AshenGravitonCleaveGASAbility.generated.h"

/**
 * UAshenGravitonCleaveGASAbility
 * 
 * Kaelen slams downward from a high void leap, crashing down with 2.5x kinetic force and stunning hovering automatons.
 */
UCLASS()
class ASHENOATH_API UAshenGravitonCleaveGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGravitonCleaveGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Kaelen")
	float DownwardKineticMultiplier = 2.5f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Kaelen")
	float ImpactRadiusUU = 450.0f;
};
