// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenSeveranceTypes.h"
#include "AshenSomaticBloodrageGASAbility.generated.h"

/**
 * UAshenSomaticBloodrageGASAbility
 * 
 * Somatic Bloodrage: Unleashes +30% bonus weapon damage and blood-dripping visual shaders following consecutive dismemberments.
 */
UCLASS()
class ASHENOATH_API UAshenSomaticBloodrageGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSomaticBloodrageGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Severance")
	float DamageBonusMultiplier = 1.30f;
};
