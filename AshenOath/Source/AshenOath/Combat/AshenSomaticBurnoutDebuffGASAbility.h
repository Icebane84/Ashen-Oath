// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenSomaticBurnoutDebuffGASAbility.generated.h"

/**
 * UAshenSomaticBurnoutDebuffGASAbility
 * 
 * Passive GAS ability applied to companion when burnout reaches Strained/Exhausted tiers:
 * - Increases dodge recovery frames
 * - Reduces stamina regeneration
 */
UCLASS()
class ASHENOATH_API UAshenSomaticBurnoutDebuffGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSomaticBurnoutDebuffGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Burnout")
	float RecoveryDelayPenalty = 0.35f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Burnout")
	float StaminaRegenPenaltyScalar = 0.25f;
};
