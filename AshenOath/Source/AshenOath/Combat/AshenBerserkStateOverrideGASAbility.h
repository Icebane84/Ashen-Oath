// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenBerserkStateOverrideGASAbility.generated.h"

/**
 * UAshenBerserkStateOverrideGASAbility
 * 
 * High-risk state override:
 * - Movement Speed +150%
 * - 100% Stagger Immunity
 * - Continuous Health Burn (fuel source)
 * - Strips HUD telemetry
 */
UCLASS()
class ASHENOATH_API UAshenBerserkStateOverrideGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenBerserkStateOverrideGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Berserk")
	float MovementSpeedMultiplier = 2.50f; // +150%

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Berserk")
	float HealthDrainPerSecondPercent = 0.03f; // 3% per second
};
