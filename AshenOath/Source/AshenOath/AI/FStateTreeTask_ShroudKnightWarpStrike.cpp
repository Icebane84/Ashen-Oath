// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "FStateTreeTask_ShroudKnightWarpStrike.h"
#include "AshenShroudKnight.h"
#include "StateTreeExecutionContext.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

EStateTreeRunStatus FStateTreeTask_ShroudKnightWarpStrike::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.ElapsedTime = 0.0f;
	InstanceData.bStrikeExecuted = false;

	AActor* OwnerActor = Cast<AActor>(Context.GetOwner());
	if (AAshenShroudKnight* Knight = Cast<AAshenShroudKnight>(OwnerActor))
	{
		InstanceData.CachedKnight = Knight;

		if (!InstanceData.TargetActor.IsValid())
		{
			InstanceData.TargetActor = UGameplayStatics::GetPlayerPawn(OwnerActor->GetWorld(), 0);
		}

		AActor* Target = InstanceData.TargetActor.IsValid() ? InstanceData.TargetActor.Get() : nullptr;
		Knight->ExecuteWarpStrike(Target);

		if (ACharacter* TargetChar = Cast<ACharacter>(Target))
		{
			Knight->ApplyCreepingParanoia(TargetChar, 0.4f);
		}

		UE_LOG(LogTemp, Warning, TEXT("FStateTreeTask_ShroudKnightWarpStrike: Executed Warp-Strike!"));
		return EStateTreeRunStatus::Running;
	}

	return EStateTreeRunStatus::Failed;
}

EStateTreeRunStatus FStateTreeTask_ShroudKnightWarpStrike::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.ElapsedTime += DeltaTime;

	if (!InstanceData.CachedKnight.IsValid())
	{
		return EStateTreeRunStatus::Failed;
	}

	AAshenShroudKnight* Knight = InstanceData.CachedKnight.Get();
	if (Knight->CurrentState != EShroudKnightState::WarpStriking && InstanceData.ElapsedTime > 0.5f)
	{
		return EStateTreeRunStatus::Succeeded;
	}

	if (InstanceData.ElapsedTime >= InstanceData.AttackTimeout)
	{
		return EStateTreeRunStatus::Succeeded;
	}

	return EStateTreeRunStatus::Running;
}

void FStateTreeTask_ShroudKnightWarpStrike::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	if (InstanceData.CachedKnight.IsValid())
	{
		AAshenShroudKnight* Knight = InstanceData.CachedKnight.Get();
		if (Knight->CurrentState == EShroudKnightState::WarpStriking)
		{
			Knight->SetAIState(EShroudKnightState::Stalking);
		}
	}
}
