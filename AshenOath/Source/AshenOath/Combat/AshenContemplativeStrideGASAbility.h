// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Companions/AshenTripartiteCognitiveLoopTypes.h"
#include "AshenContemplativeStrideGASAbility.generated.h"

/**
 * UAshenContemplativeStrideGASAbility
 * 
 * Exploration-mode companion pacing ability matching Kaelen's movement speed and maintaining wordless solidarity.
 */
UCLASS()
class ASHENOATH_API UAshenContemplativeStrideGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenContemplativeStrideGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Exploration|Stride")
	float StrideMatchDistanceToleranceUU = 50.0f;
};
