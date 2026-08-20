// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenInnerVoiceCombatStanceGASAbility.h"

UAshenInnerVoiceCombatStanceGASAbility::UAshenInnerVoiceCombatStanceGASAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	FrictionThresholdForVoice = 0.50f;
}

void UAshenInnerVoiceCombatStanceGASAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

bool UAshenInnerVoiceCombatStanceGASAbility::TriggerStanceVoiceEcho(
	const FGameplayTag& NewStanceTag,
	float CurrentFriction)
{
	if (CurrentFriction >= FrictionThresholdForVoice)
	{
		EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
		return true;
	}
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
	return false;
}

void UAshenInnerVoiceCombatStanceGASAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
