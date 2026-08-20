// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenSomaticWillStruggleGASAbility.h"
#include "AbilitySystemComponent.h"
#include "Engine/World.h"
#include "Orchestration/AshenUniversalSomaticEngineSubsystem.h"

UAshenSomaticWillStruggleGASAbility::UAshenSomaticWillStruggleGASAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	RequiredHoldDuration = 2.0f;
	MinSqueezePressureThreshold = 0.70f;
	TrialContext = EWillContext::DialogueGraceSqueeze;
	AccumulatedHoldTime = 0.0f;
	bTrialResolved = false;
}

void UAshenSomaticWillStruggleGASAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	AccumulatedHoldTime = 0.0f;
	bTrialResolved = false;

	// Capture immutable session snapshot
	ActiveSnapshot.InitialTransactionId = FGuid::NewGuid();
	ActiveSnapshot.InitialStateVersion = 1;
	ActiveSnapshot.StartTimestamp = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0;
	ActiveSnapshot.SnapshotResistanceSomatic = 0.85f;

	if (UWorld* World = GetWorld())
	{
		if (UAshenUniversalSomaticEngineSubsystem* SomaticSub = World->GetSubsystem<UAshenUniversalSomaticEngineSubsystem>())
		{
			const FSomaticState& CurrentState = SomaticSub->GetLatestSomaticState();
			ActiveSnapshot.InitialTransactionId = CurrentState.SourceTransactionId;
			ActiveSnapshot.InitialStateVersion = CurrentState.SourceStateVersion;
		}
	}
}

void UAshenSomaticWillStruggleGASAbility::RegisterSqueezeInputPulse(float DeltaTime, float SqueezePressure)
{
	if (bTrialResolved)
	{
		return;
	}

	if (SqueezePressure >= MinSqueezePressureThreshold)
	{
		AccumulatedHoldTime += DeltaTime;
		if (AccumulatedHoldTime >= RequiredHoldDuration)
		{
			bTrialResolved = true;
			// Triumph achieved
			EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
		}
	}
	else
	{
		// Pressure dropped during hold
		InterruptedSqueezeRelease();
	}
}

void UAshenSomaticWillStruggleGASAbility::InterruptedSqueezeRelease()
{
	if (bTrialResolved)
	{
		return;
	}

	bTrialResolved = true;
	// Squeeze interrupted / released early
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
}

float UAshenSomaticWillStruggleGASAbility::GetCompletionRatio() const
{
	if (RequiredHoldDuration <= 0.0f)
	{
		return 1.0f;
	}
	return FMath::Clamp(AccumulatedHoldTime / RequiredHoldDuration, 0.0f, 1.0f);
}

void UAshenSomaticWillStruggleGASAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
