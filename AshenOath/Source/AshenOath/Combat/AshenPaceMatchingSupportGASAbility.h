// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenPaceMatchingSupportGASAbility.generated.h"

/**
 * UAshenPaceMatchingSupportGASAbility
 * 
 * Companion ability synchronizing locomotion velocity to match Kaelen's stride.
 */
UCLASS()
class ASHENOATH_API UAshenPaceMatchingSupportGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenPaceMatchingSupportGASAbility();

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

	/** Synchronizes locomotion speed scalar */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Locomotion")
	void SyncPaceWithKaelen(float KaelenSpeed);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Locomotion")
	float MatchedSpeedScalar = 1.0f;
};
