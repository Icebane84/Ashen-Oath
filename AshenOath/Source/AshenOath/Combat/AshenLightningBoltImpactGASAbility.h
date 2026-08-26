// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenDynamicWeatherTypes.h"
#include "AshenLightningBoltImpactGASAbility.generated.h"

/**
 * UAshenLightningBoltImpactGASAbility
 * 
 * Environmental hazard strike ability delivering 850 shock damage and ragdoll physics knockdown to targets caught in the strike circle.
 */
UCLASS()
class ASHENOATH_API UAshenLightningBoltImpactGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenLightningBoltImpactGASAbility();

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
	float BaseShockDamage = 850.0f;
};
