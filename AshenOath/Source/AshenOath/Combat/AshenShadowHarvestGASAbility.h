// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenBleedingWaystationTypes.h"
#include "AshenShadowHarvestGASAbility.generated.h"

/**
 * UAshenShadowHarvestGASAbility
 * 
 * Kaelen drains the pinned scout's residual Shadow Taint for +35% combat damage and desaturating post-process.
 */
UCLASS()
class ASHENOATH_API UAshenShadowHarvestGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenShadowHarvestGASAbility();

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
	float HarvestDamageBoost = 1.35f;
};
