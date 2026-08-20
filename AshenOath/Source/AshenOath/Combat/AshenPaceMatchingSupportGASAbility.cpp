// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenPaceMatchingSupportGASAbility.h"

UAshenPaceMatchingSupportGASAbility::UAshenPaceMatchingSupportGASAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	MatchedSpeedScalar = 1.0f;
}

void UAshenPaceMatchingSupportGASAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UAshenPaceMatchingSupportGASAbility::SyncPaceWithKaelen(float KaelenSpeed)
{
	MatchedSpeedScalar = FMath::Clamp(KaelenSpeed / 600.0f, 0.40f, 1.20f);
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
}

void UAshenPaceMatchingSupportGASAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
