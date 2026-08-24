// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario9Types.h"
#include "AshenZeroGOrbitalLungeGASAbility.generated.h"

/**
 * UAshenZeroGOrbitalLungeGASAbility
 * 
 * Kinetic lunge traversing floating island chasms in low-gravity with 2.5x reach and dynamic aerial tracking.
 */
UCLASS()
class ASHENOATH_API UAshenZeroGOrbitalLungeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenZeroGOrbitalLungeGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Lunge")
	float ReachMultiplier = 2.5f;
};
