// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenEmpathicTransferenceSootGASAbility.h"

UAshenEmpathicTransferenceSootGASAbility::UAshenEmpathicTransferenceSootGASAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	MaxDysregulationRelief = 0.45f;
	SerafinaSootConversionRatio = 0.70f;
}

void UAshenEmpathicTransferenceSootGASAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

float UAshenEmpathicTransferenceSootGASAbility::PerformTransferenceChannel(float TargetKaelenDysregulation)
{
	const float Relief = FMath::Min(TargetKaelenDysregulation, MaxDysregulationRelief);
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
	return Relief;
}

void UAshenEmpathicTransferenceSootGASAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
