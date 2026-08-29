// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenSeveranceTypes.h"
#include "AshenExecuteSeveranceCleaveGASAbility.generated.h"

/**
 * UAshenExecuteSeveranceCleaveGASAbility
 * 
 * Executioner's Cleave: Triggers a high-momentum lethal severance strike on a poise-broken enemy, triggering anatomical bone slicing, blood splatters, and adrenaline recovery.
 */
UCLASS()
class ASHENOATH_API UAshenExecuteSeveranceCleaveGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenExecuteSeveranceCleaveGASAbility();

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
	ESeveranceBoneTarget TargetBone = ESeveranceBoneTarget::TorsoWaist;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Severance")
	float ExecutionDamage = 450.0f;
};
