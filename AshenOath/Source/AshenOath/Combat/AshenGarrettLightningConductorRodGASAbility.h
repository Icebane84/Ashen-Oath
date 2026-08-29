// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenDestructionWeatherAITypes.h"
#include "AshenGarrettLightningConductorRodGASAbility.generated.h"

/**
 * UAshenGarrettLightningConductorRodGASAbility
 * 
 * Garrett Tactical Ability: Plants an alchemical copper grounding rod that attracts all environmental lightning strikes within 800uu, shielding the party and discharging 450 Shock Damage to nearby hostiles.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettLightningConductorRodGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettLightningConductorRodGASAbility();

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
	float AttractionRadiusUU = 800.0f;
};
