// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenMarginaliaPenmanshipGASAbility.h"

UAshenMarginaliaPenmanshipGASAbility::UAshenMarginaliaPenmanshipGASAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
}

void UAshenMarginaliaPenmanshipGASAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

bool UAshenMarginaliaPenmanshipGASAbility::RecordCombatPenmanshipMark(
	const FString& TargetMemoryId,
	EMarginaliaAuthor Author)
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
	return true;
}

void UAshenMarginaliaPenmanshipGASAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
