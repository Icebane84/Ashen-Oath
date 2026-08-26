// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenDynamicRubbleTypes.h"
#include "AshenGarrettBreachingChargeGASAbility.generated.h"

/**
 * UAshenGarrettBreachingChargeGASAbility
 * 
 * Garrett plants an alchemical breaching charge, detonating structural masonry to create new tactical flanking paths.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettBreachingChargeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettBreachingChargeGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Demolition")
	float BreachingExplosiveForce = 850.0f;
};
