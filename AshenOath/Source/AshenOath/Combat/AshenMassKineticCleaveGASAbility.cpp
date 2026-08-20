// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenMassKineticCleaveGASAbility.h"

UAshenMassKineticCleaveGASAbility::UAshenMassKineticCleaveGASAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
}

void UAshenMassKineticCleaveGASAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

FKineticSwingSnapshot UAshenMassKineticCleaveGASAbility::ExecuteCleaveStrike(
	EKineticCleaveStance Stance,
	float TipVelocity)
{
	FKineticSwingSnapshot Snapshot;
	Snapshot.SwingId = FGuid::NewGuid().ToString(EGuidFormats::DigitsWithHyphensLower);
	Snapshot.Stance = Stance;

	const float MassKG = (Stance == EKineticCleaveStance::DarkShadowUnleashed) ? 180.0f : 45.0f;
	Snapshot.WeaponMassKG = MassKG;
	Snapshot.BladeTipVelocity = TipVelocity * 100.0f;

	float Energy = 0.5f * MassKG * (TipVelocity * TipVelocity);
	if (Stance == EKineticCleaveStance::DarkShadowUnleashed)
	{
		Energy *= 2.5f;
	}
	Snapshot.KineticEnergyJoules = Energy;

	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
	return Snapshot;
}

void UAshenMassKineticCleaveGASAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
