// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "AshenStanceFlowCancelRhythmGASAbility.generated.h"

/**
 * UAshenStanceFlowCancelRhythmGASAbility
 * 
 * Executes the rhythm-timed Flow Glint recovery cancel, transitioning stance with 0 stamina cost and granting +25% kinetic momentum.
 */
UCLASS()
class ASHENOATH_API UAshenStanceFlowCancelRhythmGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenStanceFlowCancelRhythmGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Oathbringer")
	float FlowGlintMomentumBonus = 0.25f;
};
