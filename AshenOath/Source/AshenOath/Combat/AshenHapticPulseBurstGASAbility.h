// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Haptics/AshenDualSenseHapticTypes.h"
#include "AshenHapticPulseBurstGASAbility.generated.h"

/**
 * UAshenHapticPulseBurstGASAbility
 * 
 * Delivers a sharp high-frequency vibrational burst to controller grip motors.
 */
UCLASS()
class ASHENOATH_API UAshenHapticPulseBurstGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenHapticPulseBurstGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Haptics")
	float PulseIntensity = 0.85f;
};
