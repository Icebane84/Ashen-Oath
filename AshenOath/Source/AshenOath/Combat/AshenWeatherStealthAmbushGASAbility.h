// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenDestructionWeatherAITypes.h"
#include "AshenWeatherStealthAmbushGASAbility.generated.h"

/**
 * UAshenWeatherStealthAmbushGASAbility
 * 
 * Storm Stealth Ambush: Grants +50% critical strike damage when striking targets while cloaked inside dense blizzard whiteouts or ash storms.
 */
UCLASS()
class ASHENOATH_API UAshenWeatherStealthAmbushGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenWeatherStealthAmbushGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Convergence")
	float CriticalDamageBonus = 0.50f;
};
