// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "FStateTreeTask_BossPhaseTransition.h"
#include "AshenPAAMasterOrchestrator.h"
#include "StateTreeExecutionContext.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

EStateTreeRunStatus FStateTreeTask_BossPhaseTransition::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.ElapsedTime = 0.0f;
	InstanceData.bPhaseInitialized = false;

	AActor* BossActor = Cast<AActor>(Context.GetOwner());
	if (!BossActor)
	{
		return EStateTreeRunStatus::Failed;
	}

	// Update PAA Orchestrator Encounter Tier
	if (UWorld* World = BossActor->GetWorld())
	{
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenPAAMasterOrchestrator* Orchestrator = GI->GetSubsystem<UAshenPAAMasterOrchestrator>())
			{
				Orchestrator->RunProductionArchitectureAuditPass(FName(TEXT("Encounter.BossPhaseTransition")));
				InstanceData.bPhaseInitialized = true;
				UE_LOG(LogTemp, Warning, TEXT("FStateTreeTask_BossPhaseTransition: Boss Phase Transition initiated to Tier %d!"),
					static_cast<int32>(InstanceData.NextEncounterTier));
			}
		}
	}

	return EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FStateTreeTask_BossPhaseTransition::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.ElapsedTime += DeltaTime;

	if (InstanceData.ElapsedTime >= InstanceData.TransitionDuration)
	{
		return EStateTreeRunStatus::Succeeded;
	}

	return EStateTreeRunStatus::Running;
}

void FStateTreeTask_BossPhaseTransition::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	UE_LOG(LogTemp, Log, TEXT("FStateTreeTask_BossPhaseTransition: Boss Phase Transition complete. Boss entering new phase."));
}
