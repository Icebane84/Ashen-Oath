// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenCompanionTacticalOrderAbility.h"

UAshenCompanionTacticalOrderAbility::UAshenCompanionTacticalOrderAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	SquadCommandType = EAshenSquadCommand::Garrett_PauldronVault;
	FatigueAccrual = 0.25f;
}

void UAshenCompanionTacticalOrderAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	UE_LOG(LogTemp, Log, TEXT("AshenCompanionTacticalOrderAbility: Executed command type %d with fatigue %f"),
		(int32)SquadCommandType, FatigueAccrual);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
