// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Companions/AshenCompanionIntentTypes.h"
#include "AshenShoulderToShoulderCommitGASAbility.generated.h"

/**
 * UAshenShoulderToShoulderCommitGASAbility
 * 
 * GAS ability triggered when high-trust companion rushes shoulder-to-shoulder with Kaelen:
 * - 1.35x Sprint speed boost
 * - +40% Mutual Poise Hardening
 */
UCLASS()
class ASHENOATH_API UAshenShoulderToShoulderCommitGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenShoulderToShoulderCommitGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Poise")
	float MutualPoiseHardeningScalar = 0.40f;
};
