// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenConsumeSurvivalMealGASAbility.h"

UAshenConsumeSurvivalMealGASAbility::UAshenConsumeSurvivalMealGASAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	MealTypeToConsume = ECookedMealBuffType::GlacialHeartStew;
	BuffDurationSeconds = 900.0f;
}

void UAshenConsumeSurvivalMealGASAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UAshenConsumeSurvivalMealGASAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
