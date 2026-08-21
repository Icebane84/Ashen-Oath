// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenHarmonizedRadiantFinisherGASAbility.h"

UAshenHarmonizedRadiantFinisherGASAbility::UAshenHarmonizedRadiantFinisherGASAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	DamageMultiplier = 3.50f;
	DysregulationPurgePercent = 0.30f;
}

void UAshenHarmonizedRadiantFinisherGASAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

float UAshenHarmonizedRadiantFinisherGASAbility::ExecuteFinisher(AActor* TargetActor, float BaseDamage)
{
	const float TotalDamage = BaseDamage * DamageMultiplier;
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
	return TotalDamage;
}

void UAshenHarmonizedRadiantFinisherGASAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
