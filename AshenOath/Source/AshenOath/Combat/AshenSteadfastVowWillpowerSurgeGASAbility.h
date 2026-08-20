// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenSteadfastVowWillpowerSurgeGASAbility.generated.h"

/**
 * UAshenSteadfastVowWillpowerSurgeGASAbility
 * 
 * Vow ability granting +40% Poise and +25% Willpower when Kaelen honors
 * a solemn promise under extreme combat pressure.
 */
UCLASS()
class ASHENOATH_API UAshenSteadfastVowWillpowerSurgeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSteadfastVowWillpowerSurgeGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Vow")
	float PoiseBonusPercent = 40.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Vow")
	float WillpowerBonusPercent = 25.0f;
};
