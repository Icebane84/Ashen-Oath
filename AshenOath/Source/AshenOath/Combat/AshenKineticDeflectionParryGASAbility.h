// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenKineticDeflectionParryGASAbility.generated.h"

/**
 * UAshenKineticDeflectionParryGASAbility
 * 
 * High-precision 120ms parry window redirecting kinetic force:
 * - 100% damage mitigation
 * - Heavy posture damage inflicted on attacker
 * - Hit-stop time dilation (0.01 for 60ms)
 */
UCLASS()
class ASHENOATH_API UAshenKineticDeflectionParryGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenKineticDeflectionParryGASAbility();

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

	/** Evaluates whether an incoming strike lands within the deflection window */
	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|Parry")
	bool EvaluateDeflectionSuccess(float DeltaTimestampSeconds) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Parry")
	float DeflectionWindowSeconds = 0.12f; // 120ms
};
