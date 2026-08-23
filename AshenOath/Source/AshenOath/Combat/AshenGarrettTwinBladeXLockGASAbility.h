// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenBleedingWaystationTypes.h"
#include "AshenGarrettTwinBladeXLockGASAbility.generated.h"

/**
 * UAshenGarrettTwinBladeXLockGASAbility
 * 
 * Garrett's dual-wield cross-blade parry (X-Lock) deflecting descending strikes over Kaelen's head with a kick counter.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettTwinBladeXLockGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettTwinBladeXLockGASAbility();

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
	float DeflectWindowSeconds = 0.45f;
};
