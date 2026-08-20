// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenKineticDeflectionParryGASAbility.h"

UAshenKineticDeflectionParryGASAbility::UAshenKineticDeflectionParryGASAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	DeflectionWindowSeconds = 0.12f;
}

void UAshenKineticDeflectionParryGASAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

bool UAshenKineticDeflectionParryGASAbility::EvaluateDeflectionSuccess(float DeltaTimestampSeconds) const
{
	return (DeltaTimestampSeconds >= 0.0f && DeltaTimestampSeconds <= DeflectionWindowSeconds);
}

void UAshenKineticDeflectionParryGASAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
