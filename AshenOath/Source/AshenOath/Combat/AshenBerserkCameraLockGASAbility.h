// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenKineticBerserkTypes.h"
#include "AshenBerserkCameraLockGASAbility.generated.h"

/**
 * UAshenBerserkCameraLockGASAbility
 * 
 * Gameplay Ability activating 1200cm sphere-sweep target tracking camera lock during frenzy.
 */
UCLASS()
class ASHENOATH_API UAshenBerserkCameraLockGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenBerserkCameraLockGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|KineticBerserk|GAS")
	float TrackingRadiusCentimeters = 1200.0f;
};
