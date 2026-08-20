// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenWordlessObstacleClearGASAbility.generated.h"

/**
 * UAshenWordlessObstacleClearGASAbility
 * 
 * Garrett's proactive ability clearing debris before Kaelen arrives.
 */
UCLASS()
class ASHENOATH_API UAshenWordlessObstacleClearGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenWordlessObstacleClearGASAbility();

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

	/** Executes clearance of target obstacle actor */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Silence")
	bool ExecuteObstacleClear(AActor* ObstacleActor);
};
