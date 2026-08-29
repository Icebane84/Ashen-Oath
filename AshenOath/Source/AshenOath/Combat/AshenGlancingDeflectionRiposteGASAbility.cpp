// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenGlancingDeflectionRiposteGASAbility.h"

UAshenGlancingDeflectionRiposteGASAbility::UAshenGlancingDeflectionRiposteGASAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	StaminaRestored = 50.0f;
	WhiteFlameGained = 35.0f;
}

void UAshenGlancingDeflectionRiposteGASAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UAshenGlancingDeflectionRiposteGASAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
