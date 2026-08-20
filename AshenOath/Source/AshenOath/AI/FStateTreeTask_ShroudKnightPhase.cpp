// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "FStateTreeTask_ShroudKnightPhase.h"
#include "AshenShroudKnight.h"
#include "StateTreeExecutionContext.h"
#include "GameFramework/Actor.h"

EStateTreeRunStatus FStateTreeTask_ShroudKnightPhase::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.ElapsedTime = 0.0f;

	AActor* OwnerActor = Cast<AActor>(Context.GetOwner());
	if (AAshenShroudKnight* Knight = Cast<AAshenShroudKnight>(OwnerActor))
	{
		InstanceData.CachedKnight = Knight;
		Knight->InitiatePhaseShift();
		UE_LOG(LogTemp, Warning, TEXT("FStateTreeTask_ShroudKnightPhase: Spectral Phase Shift initiated!"));
		return EStateTreeRunStatus::Running;
	}

	return EStateTreeRunStatus::Failed;
}

EStateTreeRunStatus FStateTreeTask_ShroudKnightPhase::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.ElapsedTime += DeltaTime;

	if (!InstanceData.CachedKnight.IsValid())
	{
		return EStateTreeRunStatus::Failed;
	}

	AAshenShroudKnight* Knight = InstanceData.CachedKnight.Get();
	if (Knight->CurrentState == EShroudKnightState::ConsecratedStun || Knight->CurrentState == EShroudKnightState::PinnedByKaelen)
	{
		UE_LOG(LogTemp, Warning, TEXT("FStateTreeTask_ShroudKnightPhase: Phase Shift interrupted by stun/pin lock!"));
		return EStateTreeRunStatus::Failed;
	}

	if (InstanceData.ElapsedTime >= InstanceData.PhaseDuration)
	{
		return EStateTreeRunStatus::Succeeded;
	}

	return EStateTreeRunStatus::Running;
}

void FStateTreeTask_ShroudKnightPhase::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	if (InstanceData.CachedKnight.IsValid())
	{
		InstanceData.CachedKnight->TerminatePhaseShift(false);
	}
}
