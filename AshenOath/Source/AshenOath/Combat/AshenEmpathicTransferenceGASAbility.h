// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenEmpathicTransferenceGASAbility.generated.h"

/**
 * UAshenEmpathicTransferenceGASAbility
 * 
 * Serafina's sacrificial heal ability:
 * - Instantly restores target health by absorbing their trauma
 * - Channels equivalent strain into Serafina's somatic burnout pool
 */
UCLASS()
class ASHENOATH_API UAshenEmpathicTransferenceGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenEmpathicTransferenceGASAbility();

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

	/** Executes transference healing on target actor */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Transference")
	bool ExecuteTransferenceHeal(AActor* TargetActor, float HealAmount);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Transference")
	float BaseTransferenceEfficiency = 1.0f;
};
