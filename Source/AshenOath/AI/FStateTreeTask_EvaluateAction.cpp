// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 416: FStateTreeTask_EvaluateAction

#include "FStateTreeTask_EvaluateAction.h"
#include "StateTreeExecutionContext.h"
#include "AIController.h"
#include "AbilitySystemGlobals.h"
#include "AbilitySystemComponent.h"
#include "AshenOath_StaminaComponent.h"
#include "UAICognitiveComponent.h"

EStateTreeRunStatus FStateTreeTask_EvaluateAction::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);

	const AAIController* AIController = Cast<AAIController>(Context.GetOwner());
	if (const APawn* AIPawn = AIController ? AIController->GetPawn() : nullptr)
	{
		InstanceData.CachedCognitiveComp = AIPawn->FindComponentByClass<UAICognitiveComponent>();
	}

	return EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FStateTreeTask_EvaluateAction::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);

	AAIController* AIController = Cast<AAIController>(Context.GetOwner());
	if (!AIController) return EStateTreeRunStatus::Failed;

	APawn* AIPawn = AIController->GetPawn();
	if (!AIPawn) return EStateTreeRunStatus::Failed;

	if (!InstanceData.CachedCognitiveComp.IsValid())
	{
		InstanceData.CachedCognitiveComp = AIPawn->FindComponentByClass<UAICognitiveComponent>();
	}

	UAICognitiveComponent* CognitiveComp = InstanceData.CachedCognitiveComp.Get();
	if (!CognitiveComp) return EStateTreeRunStatus::Failed;

	APawn* TargetActor = CognitiveComp->GetPrimaryThreatTarget();
	if (!TargetActor)
	{
		InstanceData.OutCalculatedUtility = 0.0f;
		return EStateTreeRunStatus::Failed;
	}

	UAbilitySystemComponent* TargetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(TargetActor);
	float InputReadingModifier = 1.0f;

	if (TargetASC && InstanceData.PunishTriggerTag.IsValid() && TargetASC->HasMatchingGameplayTag(InstanceData.PunishTriggerTag))
	{
		const float Dist = FVector::Dist(AIPawn->GetActorLocation(), TargetActor->GetActorLocation());
		if (Dist < InstanceData.PunishRange)
		{
			InputReadingModifier = InstanceData.PunishMultiplier;
		}
	}

	float StaminaFactor = 1.0f;
	const UAshenOath_StaminaComponent* StaminaComp = AIPawn->FindComponentByClass<UAshenOath_StaminaComponent>();
	if (StaminaComp)
	{
		StaminaFactor = StaminaComp->GetCurrentStamina() / FMath::Max(1.0f, StaminaComp->GetMaxStamina());
	}

	const float CurrentDistance = FVector::Dist(AIPawn->GetActorLocation(), TargetActor->GetActorLocation());
	const float DistanceDelta = FMath::Abs(CurrentDistance - InstanceData.PreferredRange);
	const float DistanceScore = 1.0f / (1.0f + (DistanceDelta * 0.002f));

	const int32 RecentExecutions = CognitiveComp->GetRecentExecutionCount(InstanceData.ActionTypeTag, InstanceData.EntropyWindowSeconds);
	const float EntropyDecay = FMath::Max(0.1f, 1.0f - (InstanceData.EntropyGamma * RecentExecutions));

	InstanceData.OutCalculatedUtility = InstanceData.BaseUtility * DistanceScore * StaminaFactor * InputReadingModifier * EntropyDecay;

	return EStateTreeRunStatus::Running;
}
