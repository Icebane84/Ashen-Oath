// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenCampfireCookingTypes.h"
#include "AshenConsumeCampfireMealGASAbility.generated.h"

/**
 * UAshenConsumeCampfireMealGASAbility
 * 
 * Party ability: Consumes a portion of freshly prepared campfire stew, applying a 10-minute persistent morale buff.
 */
UCLASS()
class ASHENOATH_API UAshenConsumeCampfireMealGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenConsumeCampfireMealGASAbility();

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
	float BuffDurationSeconds = 600.0f;
};
