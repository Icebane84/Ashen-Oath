// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Companions/AshenRelationalEcologyTypes.h"
#include "AshenEmpathicTransferenceSootGASAbility.generated.h"

/**
 * UAshenEmpathicTransferenceSootGASAbility
 * 
 * Gameplay Ability executing Empathic Transference:
 * - Serafina channels light energy through Kaelen's heart
 * - Reduces Kaelen's AccumulatedDysregulation by up to 0.45
 * - Serafina absorbs the toll, accumulating physical grey soot on her arms and wrists
 */
UCLASS()
class ASHENOATH_API UAshenEmpathicTransferenceSootGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenEmpathicTransferenceSootGASAbility();

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

	/** Executes the transference reduction */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Empathy")
	float PerformTransferenceChannel(float TargetKaelenDysregulation);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Empathy")
	float MaxDysregulationRelief = 0.45f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Empathy")
	float SerafinaSootConversionRatio = 0.70f;
};
