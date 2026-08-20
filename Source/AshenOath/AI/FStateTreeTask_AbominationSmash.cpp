// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "FStateTreeTask_AbominationSmash.h"
#include "AshenAbomination.h"
#include "StateTreeExecutionContext.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

EStateTreeRunStatus FStateTreeTask_AbominationSmash::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.ElapsedTime = 0.0f;
	InstanceData.bSmashExecuted = false;

	AActor* OwnerActor = Cast<AActor>(Context.GetOwner());
	if (AAshenAbomination* Boss = Cast<AAshenAbomination>(OwnerActor))
	{
		InstanceData.CachedBoss = Boss;
		Boss->SetBossState(EAbhenAbominationState::OverheadCrushing);
		UE_LOG(LogTemp, Warning, TEXT("FStateTreeTask_AbominationSmash: Wind-up started for Overhead Crush!"));
	}
	else
	{
		return EStateTreeRunStatus::Failed;
	}

	// Fallback target to player pawn if not explicitly set
	if (!InstanceData.TargetActor.IsValid())
	{
		InstanceData.TargetActor = UGameplayStatics::GetPlayerPawn(OwnerActor->GetWorld(), 0);
	}

	return EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FStateTreeTask_AbominationSmash::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.ElapsedTime += DeltaTime;

	if (!InstanceData.CachedBoss.IsValid())
	{
		return EStateTreeRunStatus::Failed;
	}

	AAshenAbomination* Boss = InstanceData.CachedBoss.Get();

	// Check if boss stumbled on a tripwire during attack
	if (Boss->CurrentState == EAbhenAbominationState::TripwireStumbled)
	{
		UE_LOG(LogTemp, Warning, TEXT("FStateTreeTask_AbominationSmash: Overhead Crush interrupted by tripwire stumble!"));
		return EStateTreeRunStatus::Failed;
	}

	// Trigger overhead crush at wind-up threshold
	if (!InstanceData.bSmashExecuted && InstanceData.ElapsedTime >= InstanceData.WindUpDuration)
	{
		InstanceData.bSmashExecuted = true;
		AActor* Target = InstanceData.TargetActor.IsValid() ? InstanceData.TargetActor.Get() : nullptr;
		Boss->ExecuteOverheadCrush(Target);
		UE_LOG(LogTemp, Log, TEXT("FStateTreeTask_AbominationSmash: Overhead Crush executed!"));
	}

	// Complete task when total attack animation duration finishes
	if (InstanceData.ElapsedTime >= InstanceData.TotalAttackDuration)
	{
		return EStateTreeRunStatus::Succeeded;
	}

	return EStateTreeRunStatus::Running;
}

void FStateTreeTask_AbominationSmash::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	if (InstanceData.CachedBoss.IsValid())
	{
		AAshenAbomination* Boss = InstanceData.CachedBoss.Get();
		if (Boss->CurrentState != EAbhenAbominationState::TripwireStumbled)
		{
			Boss->SetBossState(EAbhenAbominationState::Lurching);
		}
	}
}
