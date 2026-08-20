// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 417: FStateTreeTask_ExecuteAbility

#include "FStateTreeTask_ExecuteAbility.h"
#include "StateTreeExecutionContext.h"
#include "AIController.h"
#include "AbilitySystemGlobals.h"
#include "AbilitySystemComponent.h"
#include "UAICognitiveComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogAshenAIStateTree, Log, All);

EStateTreeRunStatus FStateTreeTask_ExecuteAbility::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);

	AAIController* AIController = Cast<AAIController>(Context.GetOwner());
	if (!AIController) return EStateTreeRunStatus::Failed;

	APawn* AIPawn = AIController->GetPawn();
	if (!AIPawn) return EStateTreeRunStatus::Failed;

	UAICognitiveComponent* CognitiveComp = AIPawn->FindComponentByClass<UAICognitiveComponent>();
	UAbilitySystemComponent* ASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(AIPawn);
	if (!CognitiveComp || !ASC) return EStateTreeRunStatus::Failed;

	InstanceData.CachedCognitiveComp = CognitiveComp;

	TArray<FGameplayAbilitySpecHandle> MatchingAbilities;
	ASC->FindAllAbilitiesWithTags(MatchingAbilities, FGameplayTagContainer(InstanceData.AbilityTag));

	if (MatchingAbilities.Num() == 0) return EStateTreeRunStatus::Failed;

	InstanceData.ActiveAbilityHandle = MatchingAbilities[0];
	CognitiveComp->ClearAbilityCompletion(InstanceData.ActiveAbilityHandle);

	TWeakObjectPtr<UAICognitiveComponent> WeakCognitive(CognitiveComp);
	const FGameplayAbilitySpecHandle TargetHandle = InstanceData.ActiveAbilityHandle;

	InstanceData.AbilityEndedDelegateHandle = ASC->OnAbilityEnded.AddLambda(
		[WeakCognitive, TargetHandle](const FAbilityEndedData& EndedData)
		{
			if (WeakCognitive.IsValid() && EndedData.AbilitySpecHandle == TargetHandle)
			{
				WeakCognitive->SetAbilityCompleted(TargetHandle);
			}
		}
	);

	if (!ASC->TryActivateAbility(InstanceData.ActiveAbilityHandle))
	{
		ASC->OnAbilityEnded.Remove(InstanceData.AbilityEndedDelegateHandle);
		InstanceData.AbilityEndedDelegateHandle.Reset();
		return EStateTreeRunStatus::Failed;
	}

	return EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FStateTreeTask_ExecuteAbility::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
	const FInstanceDataType& InstanceData = Context.GetInstanceData(*this);

	const UAICognitiveComponent* CognitiveComp = InstanceData.CachedCognitiveComp.Get();
	if (!CognitiveComp) return EStateTreeRunStatus::Failed;

	if (CognitiveComp->IsAbilityCompleted(InstanceData.ActiveAbilityHandle))
	{
		return EStateTreeRunStatus::Succeeded;
	}

	return EStateTreeRunStatus::Running;
}

void FStateTreeTask_ExecuteAbility::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);

	AAIController* AIController = Cast<AAIController>(Context.GetOwner());
	APawn* AIPawn = AIController ? AIController->GetPawn() : nullptr;
	UAbilitySystemComponent* ASC = AIPawn ? UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(AIPawn) : nullptr;

	if (ASC && InstanceData.AbilityEndedDelegateHandle.IsValid())
	{
		ASC->OnAbilityEnded.Remove(InstanceData.AbilityEndedDelegateHandle);
		InstanceData.AbilityEndedDelegateHandle.Reset();
	}

	if (UAICognitiveComponent* CognitiveComp = InstanceData.CachedCognitiveComp.Get())
	{
		CognitiveComp->ClearAbilityCompletion(InstanceData.ActiveAbilityHandle);
		CognitiveComp->RecordAction(InstanceData.AbilityTag);
	}

	InstanceData.ActiveAbilityHandle = FGameplayAbilitySpecHandle();
}
