// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenDynamicWeatherTypes.h"
#include "AshenAcidRainCorrosionGASAbility.generated.h"

/**
 * UAshenAcidRainCorrosionGASAbility
 * 
 * Environmental hazard execution ability eroding physical armor durability (-2.5%/s) and amplifying incoming kinetic damage (+35%).
 */
UCLASS()
class ASHENOATH_API UAshenAcidRainCorrosionGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenAcidRainCorrosionGASAbility();

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
	float DurabilityErosionRate = 0.025f;
};
