// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenAlchemicalSlagTypes.h"
#include "AshenThermalShockShatterGASAbility.generated.h"

/**
 * UAshenThermalShockShatterGASAbility
 * 
 * Thermal Shock Execution: Superheated slag blade striking a chilled or frozen target triggers rapid contraction, dealing +100% poise shatter and breaking physical armor.
 */
UCLASS()
class ASHENOATH_API UAshenThermalShockShatterGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenThermalShockShatterGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|AlchemicalSlag")
	float PoiseShatterMultiplier = 2.00f;
};
