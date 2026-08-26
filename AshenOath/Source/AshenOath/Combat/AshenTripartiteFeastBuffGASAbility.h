// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenCampfireCookingTypes.h"
#include "AshenTripartiteFeastBuffGASAbility.generated.h"

/**
 * UAshenTripartiteFeastBuffGASAbility
 * 
 * Tripartite feast synergy: Grants full party morale resonance, restoring sanity and boosting all combat attributes by +25%.
 */
UCLASS()
class ASHENOATH_API UAshenTripartiteFeastBuffGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenTripartiteFeastBuffGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Cooking")
	float AllStatsBonusPercent = 0.25f;
};
