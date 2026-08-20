// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenBoundaryHaltDisengageGASAbility.generated.h"

/**
 * UAshenBoundaryHaltDisengageGASAbility
 * 
 * Companion ability executing the boundary refusal standoff:
 * - Halts follower pathfinding at the threshold (800uu standoff)
 * - Lowers weapons into a non-aggressive posture
 */
UCLASS()
class ASHENOATH_API UAshenBoundaryHaltDisengageGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenBoundaryHaltDisengageGASAbility();

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

	/** Executes standoff halt */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Boundary")
	void ExecuteBoundaryHalt();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Boundary")
	float StandoffDistanceUU = 800.0f;
};
