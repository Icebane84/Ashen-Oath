// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenCompanionPromiseGroundingGASAbility.generated.h"

/**
 * UAshenCompanionPromiseGroundingGASAbility
 * 
 * Companion grounding ability invoking the sworn vow to clear corruption overflow
 * from Kaelen when dysregulation spikes dangerously.
 */
UCLASS()
class ASHENOATH_API UAshenCompanionPromiseGroundingGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenCompanionPromiseGroundingGASAbility();

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

	/** Executes vow grounding on Kaelen */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Vow")
	bool ExecuteVowGrounding(AActor* KaelenActor);
};
