// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenSteadfastVowWillpowerSurgeGASAbility.h"

UAshenSteadfastVowWillpowerSurgeGASAbility::UAshenSteadfastVowWillpowerSurgeGASAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	PoiseBonusPercent = 40.0f;
	WillpowerBonusPercent = 25.0f;
}

void UAshenSteadfastVowWillpowerSurgeGASAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UAshenSteadfastVowWillpowerSurgeGASAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
