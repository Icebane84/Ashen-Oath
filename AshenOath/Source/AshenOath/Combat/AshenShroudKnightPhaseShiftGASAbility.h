// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenShroudKnightTypes.h"
#include "AshenShroudKnightPhaseShiftGASAbility.generated.h"

/**
 * UAshenShroudKnightPhaseShiftGASAbility
 * 
 * Boss ability: The Shroud-Knight dissolves into dark mist, disabling collision and gliding through solid walls.
 */
UCLASS()
class ASHENOATH_API UAshenShroudKnightPhaseShiftGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenShroudKnightPhaseShiftGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Boss|Phase")
	float PhaseDurationSeconds = 4.0f;
};
