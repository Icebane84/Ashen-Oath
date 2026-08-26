// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenCampfireCookingTypes.h"
#include "AshenSerafinaTisaneBrewGASAbility.generated.h"

/**
 * UAshenSerafinaTisaneBrewGASAbility
 * 
 * Serafina's restorative brewing: Prepares White Flame herbal tisane, reducing empathic burnout accumulation by -30%.
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaTisaneBrewGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSerafinaTisaneBrewGASAbility();

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
	float BurnoutMitigationRatio = 0.30f;
};
