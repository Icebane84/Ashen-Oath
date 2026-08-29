// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenDestructionWeatherAITypes.h"
#include "AshenConductiveLightningArcGASAbility.generated.h"

/**
 * UAshenConductiveLightningArcGASAbility
 * 
 * Executes secondary conductive electrical arcs across wet acid puddles and iron debris, applying 350 Shock Damage and 1.2s paralysis stagger.
 */
UCLASS()
class ASHENOATH_API UAshenConductiveLightningArcGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenConductiveLightningArcGASAbility();

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
	float ChainArcDamage = 350.0f;
};
