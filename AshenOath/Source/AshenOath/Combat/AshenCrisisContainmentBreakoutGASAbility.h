// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Companions/AshenTripartiteCognitiveLoopTypes.h"
#include "AshenCrisisContainmentBreakoutGASAbility.generated.h"

/**
 * UAshenCrisisContainmentBreakoutGASAbility
 * 
 * Emergency companion intervention triggered during high Debt crisis, subduing Kaelen's panic tremor.
 */
UCLASS()
class ASHENOATH_API UAshenCrisisContainmentBreakoutGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenCrisisContainmentBreakoutGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Crisis")
	float DebtSuppressionAmount = 0.20f;
};
