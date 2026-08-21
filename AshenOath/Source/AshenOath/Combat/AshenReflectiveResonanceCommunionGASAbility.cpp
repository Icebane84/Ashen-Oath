// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenReflectiveResonanceCommunionGASAbility.h"

UAshenReflectiveResonanceCommunionGASAbility::UAshenReflectiveResonanceCommunionGASAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	HolyResistanceBonusPercent = 15.0f;
	PoiseBonusPercent = 10.0f;
}

void UAshenReflectiveResonanceCommunionGASAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UAshenReflectiveResonanceCommunionGASAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
