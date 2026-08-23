// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenBleedingWaystationTypes.h"
#include "AshenSerafinaTransferenceWardGASAbility.generated.h"

/**
 * UAshenSerafinaTransferenceWardGASAbility
 * 
 * Serafina deploys an empathic transference recovery ward upon Kaelen when in tight formation (0ms delay).
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaTransferenceWardGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSerafinaTransferenceWardGASAbility();

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
	float HealingAmount = 300.0f;
};
