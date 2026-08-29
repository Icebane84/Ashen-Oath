// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenFactionAutopsyMasteryBuffGASAbility.h"

UAshenFactionAutopsyMasteryBuffGASAbility::UAshenFactionAutopsyMasteryBuffGASAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	CritDamageMultiplierBonus = 0.25f;
	PoiseDamageMultiplierBonus = 0.40f;
}

void UAshenFactionAutopsyMasteryBuffGASAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UAshenFactionAutopsyMasteryBuffGASAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
