// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenGameplayAbility_CombatStrike.h"
#include "AbilitySystemComponent.h"
#include "Animation/AnimMontage.h"
#include "Soul/AshenSoulPublisher.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenGameplayAbility_CombatStrike::UAshenGameplayAbility_CombatStrike()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
}

void UAshenGameplayAbility_CombatStrike::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	// Spawn the frame-accurate CDTC-002 Flow Glint Evaluation Task
	FlowEvalTask = UAbilityTask_EvaluateMontageFlowPosition::CreateMontageFlowPositionEvaluator(
		this,
		StrikeMontage,
		StrikeParams.ApexTimeSeconds,
		StrikeParams.WindowDurationSeconds);

	if (FlowEvalTask)
	{
		FlowEvalTask->OnInputResolved.AddDynamic(this, &UAshenGameplayAbility_CombatStrike::HandleFlowTimingResolved);
		FlowEvalTask->ReadyForActivation();
	}
}

void UAshenGameplayAbility_CombatStrike::HandleFlowTimingResolved(EAshenFlowTimingResult Result)
{
	float EffectiveStaminaCost = StrikeParams.StaminaCost;

	if (Result == EAshenFlowTimingResult::Perfect)
	{
		// Perfect Flow Glint Invariant: 0 Stamina cost + Next guard transition
		EffectiveStaminaCost = 0.0f;

		// Transition next guard via SSoT Publisher
		if (UAbilitySystemComponent* ASC = GetAbilitySystemComponentFromActorInfo())
		{
			if (const UWorld* World = ASC->GetWorld())
			{
				if (const UGameInstance* GI = World->GetGameInstance())
				{
					if (UAshenSoulPublisher* Publisher = GI->GetSubsystem<UAshenSoulPublisher>())
					{
						FSoulStateVector State = Publisher->GetSoulState();
						State.Resolve = FMath::Clamp(State.Resolve + 0.02f, 0.0f, 1.0f);
						Publisher->CommitStateDirect(State);
					}
				}
			}

			if (StrikeParams.NextGuardTag.IsValid())
			{
				ASC->AddLooseGameplayTag(StrikeParams.NextGuardTag);
			}
		}
	}

	if (OnStrikeFlowGlintResolved.IsBound())
	{
		OnStrikeFlowGlintResolved.Broadcast(Result, EffectiveStaminaCost);
	}
}

void UAshenGameplayAbility_CombatStrike::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	if (FlowEvalTask)
	{
		FlowEvalTask->EndTask();
		FlowEvalTask = nullptr;
	}

	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
