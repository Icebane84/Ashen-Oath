// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenMassKineticTypes.h"
#include "AshenMassKineticCleaveGASAbility.generated.h"

/**
 * UAshenMassKineticCleaveGASAbility
 * 
 * Primary sweeping cleave ability executing kinetic socket tracing,
 * volume drag, and structural fracture calculations.
 */
UCLASS()
class ASHENOATH_API UAshenMassKineticCleaveGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenMassKineticCleaveGASAbility();

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

	/** Executes cleave strike calculation */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Kinetic")
	FKineticSwingSnapshot ExecuteCleaveStrike(EKineticCleaveStance Stance, float TipVelocity);
};
