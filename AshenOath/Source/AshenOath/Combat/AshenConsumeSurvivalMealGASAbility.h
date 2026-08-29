// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenSanctuarySurvivalTypes.h"
#include "AshenConsumeSurvivalMealGASAbility.generated.h"

/**
 * UAshenConsumeSurvivalMealGASAbility
 * 
 * Meal Ingestion Execution: Consumes campfire cooked stew/broth/cake, granting 900s of 100% biological immunity against corresponding environmental hazard.
 */
UCLASS()
class ASHENOATH_API UAshenConsumeSurvivalMealGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenConsumeSurvivalMealGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Survival")
	ECookedMealBuffType MealTypeToConsume = ECookedMealBuffType::GlacialHeartStew;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Survival")
	float BuffDurationSeconds = 900.0f;
};
