// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario4WhisperwoodTypes.h"
#include "AshenWipeSootTouchpadGASAbility.generated.h"

/**
 * UAshenWipeSootTouchpadGASAbility
 * 
 * Gameplay Ability triggered by DualSense touchpad gestures to clear soot/ash distortion from the viewport.
 */
UCLASS()
class ASHENOATH_API UAshenWipeSootTouchpadGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenWipeSootTouchpadGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Scenario4|GAS")
	float SootClearAmount = 0.35f;
};
