// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenInscribeGuardSigilGASAbility.h"

UAshenInscribeGuardSigilGASAbility::UAshenInscribeGuardSigilGASAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	TargetSocket = EGuardSigilSocket::VomTagSocket;
	SigilToInscribe = ESigilResonanceEffect::ShatteredColossus;
}

void UAshenInscribeGuardSigilGASAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UAshenInscribeGuardSigilGASAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
