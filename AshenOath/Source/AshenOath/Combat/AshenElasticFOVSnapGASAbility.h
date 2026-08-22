// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenKineticBerserkTypes.h"
#include "AshenElasticFOVSnapGASAbility.generated.h"

/**
 * UAshenElasticFOVSnapGASAbility
 * 
 * Gameplay Ability controlling camera resistance FOV compression (90° -> 76°) and elastic pop (96° -> 90°).
 */
UCLASS()
class ASHENOATH_API UAshenElasticFOVSnapGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenElasticFOVSnapGASAbility();

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
	float CompressedFOVDegrees = 76.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|KineticBerserk|GAS")
	float OvershootFOVDegrees = 96.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|KineticBerserk|GAS")
	float BaselineFOVDegrees = 90.0f;
};
