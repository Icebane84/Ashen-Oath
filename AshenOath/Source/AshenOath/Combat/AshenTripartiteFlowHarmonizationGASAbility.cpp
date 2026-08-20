// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenTripartiteFlowHarmonizationGASAbility.h"
#include "AbilitySystemComponent.h"

UAshenTripartiteFlowHarmonizationGASAbility::UAshenTripartiteFlowHarmonizationGASAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	FlowHarmonizationDuration = 8.0f;
	PartyHyperPoiseMultiplier = 2.5f;
	StaminaRegenBonusMultiplier = 1.40f;
}

void UAshenTripartiteFlowHarmonizationGASAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

bool UAshenTripartiteFlowHarmonizationGASAbility::ExecuteHarmonizedSyncFinisher(ESyncFinisherType FinisherType)
{
	// Broadcast execution event and conclude ability
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
	return true;
}

void UAshenTripartiteFlowHarmonizationGASAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
