// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenSeveranceTypes.h"
#include "AshenAdrenalineSurgeBuffGASAbility.generated.h"

/**
 * UAshenAdrenalineSurgeBuffGASAbility
 * 
 * Adrenaline Surge: Grants temporary hyper-armor, +25.0 stamina recovery, and +25% momentum following an execution.
 */
UCLASS()
class ASHENOATH_API UAshenAdrenalineSurgeBuffGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenAdrenalineSurgeBuffGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Severance")
	float BuffDurationSeconds = 6.0f;
};
