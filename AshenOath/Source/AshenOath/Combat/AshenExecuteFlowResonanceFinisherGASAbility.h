// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenRunicForgeTypes.h"
#include "AshenExecuteFlowResonanceFinisherGASAbility.generated.h"

/**
 * UAshenExecuteFlowResonanceFinisherGASAbility
 * 
 * Flow Resonance Finisher: Triggers a hybrid dual-sigil finisher strike during the 0.15s Flow Glint transition window (1.40x damage).
 */
UCLASS()
class ASHENOATH_API UAshenExecuteFlowResonanceFinisherGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenExecuteFlowResonanceFinisherGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|RunicForge")
	float HybridDamageScale = 1.40f;
};
