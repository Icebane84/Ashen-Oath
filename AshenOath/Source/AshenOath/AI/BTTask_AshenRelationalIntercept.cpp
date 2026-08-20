// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenRelationalIntercept.h"
#include "AIController.h"

UBTTask_AshenRelationalIntercept::UBTTask_AshenRelationalIntercept()
{
	NodeName = TEXT("Ashen Relational Intercept");
	InterceptArrivalDistance = 150.0f;
	MaxInterceptSprintSpeedMultiplier = 1.45f;
}

EBTNodeResult::Type UBTTask_AshenRelationalIntercept::ExecuteTask(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory)
{
	AAIController* AICon = OwnerComp.GetAIOwner();
	if (!AICon)
	{
		return EBTNodeResult::Failed;
	}

	return EBTNodeResult::Succeeded;
}
