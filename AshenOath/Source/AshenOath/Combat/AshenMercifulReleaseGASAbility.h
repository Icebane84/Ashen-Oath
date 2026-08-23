// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenBleedingWaystationTypes.h"
#include "AshenMercifulReleaseGASAbility.generated.h"

/**
 * UAshenMercifulReleaseGASAbility
 * 
 * Kaelen grants a clean, unharvested death and burial, boosting Resolve by +0.15.
 */
UCLASS()
class ASHENOATH_API UAshenMercifulReleaseGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenMercifulReleaseGASAbility();

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
	float ResolveGain = 0.15f;
};
