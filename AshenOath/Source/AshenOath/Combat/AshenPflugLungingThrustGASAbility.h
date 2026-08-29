// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "AshenPflugLungingThrustGASAbility.generated.h"

/**
 * UAshenPflugLungingThrustGASAbility
 * 
 * Pflug Guard Execution: Rapid forward thrust from the hip with -30% stamina cost, accelerated tip speed, and white flame runic wind trails.
 */
UCLASS()
class ASHENOATH_API UAshenPflugLungingThrustGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenPflugLungingThrustGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Oathbringer")
	float StaminaDiscountPercent = 0.30f;
};
