// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenBleedingWaystationTypes.h"
#include "AshenPanicFlashStrikeGASAbility.generated.h"

/**
 * UAshenPanicFlashStrikeGASAbility
 * 
 * Involuntary panic strike triggered when Kaelen's high IntegrationDebt (>=0.75) misinterprets the scout.
 */
UCLASS()
class ASHENOATH_API UAshenPanicFlashStrikeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenPanicFlashStrikeGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Waystation|GAS")
	float PanicStrikeDamage = 450.0f;
};
