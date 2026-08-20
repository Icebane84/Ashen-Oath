// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "FStateTreeTask_AbominationSweep.h"
#include "AshenAbomination.h"
#include "StateTreeExecutionContext.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

EStateTreeRunStatus FStateTreeTask_AbominationSweep::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.ElapsedTime = 0.0f;
	InstanceData.bSweepExecuted = false;

	AActor* OwnerActor = Cast<AActor>(Context.GetOwner());
	if (AAshenAbomination* Boss = Cast<AAshenAbomination>(OwnerActor))
	{
		InstanceData.CachedBoss = Boss;
		Boss->SetBossState(EAbhenAbominationState::BoneSpurSweeping);
		UE_LOG(LogTemp, Log, TEXT("FStateTreeTask_AbominationSweep: Wind-up started for Bone Spur Sweep!"));
	}
	else
	{
		return EStateTreeRunStatus::Failed;
	}

	if (!InstanceData.TargetActor.IsValid())
	{
		InstanceData.TargetActor = UGameplayStatics::GetPlayerPawn(OwnerActor->GetWorld(), 0);
	}

	return EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FStateTreeTask_AbominationSweep::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.ElapsedTime += DeltaTime;

	if (!InstanceData.CachedBoss.IsValid())
	{
		return EStateTreeRunStatus::Failed;
	}

	AAshenAbomination* Boss = InstanceData.CachedBoss.Get();

	if (Boss->CurrentState == EAbhenAbominationState::TripwireStumbled)
	{
		UE_LOG(LogTemp, Warning, TEXT("FStateTreeTask_AbominationSweep: Bone Spur Sweep interrupted by tripwire stumble!"));
		return EStateTreeRunStatus::Failed;
	}

	if (!InstanceData.bSweepExecuted && InstanceData.ElapsedTime >= InstanceData.WindUpDuration)
	{
		InstanceData.bSweepExecuted = true;
		AActor* Target = InstanceData.TargetActor.IsValid() ? InstanceData.TargetActor.Get() : nullptr;
		Boss->ExecuteBoneSpurSweep(Target);
		UE_LOG(LogTemp, Log, TEXT("FStateTreeTask_AbominationSweep: Bone Spur Sweep executed!"));
	}

	if (InstanceData.ElapsedTime >= InstanceData.TotalAttackDuration)
	{
		return EStateTreeRunStatus::Succeeded;
	}

	return EStateTreeRunStatus::Running;
}

void FStateTreeTask_AbominationSweep::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
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
