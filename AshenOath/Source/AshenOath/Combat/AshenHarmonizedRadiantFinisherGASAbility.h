// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenTripartiteResonanceTypes.h"
#include "AshenHarmonizedRadiantFinisherGASAbility.generated.h"

/**
 * UAshenHarmonizedRadiantFinisherGASAbility
 * 
 * 3-person synchronized group finisher:
 * - Deals 3.5x devastating damage
 * - Cleanses 30% of Kaelen's accumulated dysregulation
 * - Grants +0.15 Faith/Trust
 */
UCLASS()
class ASHENOATH_API UAshenHarmonizedRadiantFinisherGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenHarmonizedRadiantFinisherGASAbility();

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

	/** Executes the finisher on the target actor */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Trio")
	float ExecuteFinisher(AActor* TargetActor, float BaseDamage);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Trio")
	float DamageMultiplier = 3.50f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Trio")
	float DysregulationPurgePercent = 0.30f;
};
