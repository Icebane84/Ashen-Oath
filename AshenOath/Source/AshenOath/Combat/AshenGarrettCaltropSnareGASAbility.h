// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario2SentinelsGambitTypes.h"
#include "AshenGarrettCaltropSnareGASAbility.generated.h"

/**
 * UAshenGarrettCaltropSnareGASAbility
 * 
 * Gameplay Ability deploying a physicalized caltrop snare in the vault corridor.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettCaltropSnareGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettCaltropSnareGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Scenario2|GAS")
	float SnareRootDurationSeconds = 4.0f;
};
