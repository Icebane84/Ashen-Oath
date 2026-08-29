// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenRunicForgeTypes.h"
#include "AshenColossusRuptureCleaveGASAbility.generated.h"

/**
 * UAshenColossusRuptureCleaveGASAbility
 * 
 * Vom Tag Sigil Inscription: Unleashes a 600uu terrain fissure delivering +150.0 Earth Poise Damage.
 */
UCLASS()
class ASHENOATH_API UAshenColossusRuptureCleaveGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenColossusRuptureCleaveGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|RunicForge")
	float FissureRadiusUU = 600.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|RunicForge")
	float BonusPoiseDamage = 150.0f;
};
