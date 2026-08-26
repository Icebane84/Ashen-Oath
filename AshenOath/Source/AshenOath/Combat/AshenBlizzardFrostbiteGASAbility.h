// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenDynamicWeatherTypes.h"
#include "AshenBlizzardFrostbiteGASAbility.generated.h"

/**
 * UAshenBlizzardFrostbiteGASAbility
 * 
 * Environmental hazard execution ability applying -30% movement slow and -20% stamina recovery in severe blizzard conditions.
 */
UCLASS()
class ASHENOATH_API UAshenBlizzardFrostbiteGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenBlizzardFrostbiteGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Weather")
	float MovementSlowRatio = 0.30f;
};
