// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenPerformCampfireIdle.h"
#include "AIController.h"

UBTTask_AshenPerformCampfireIdle::UBTTask_AshenPerformCampfireIdle()
{
	NodeName = TEXT("Ashen Perform Campfire Idle");
	IdleActionName = TEXT("SharpenBlade");
}

EBTNodeResult::Type UBTTask_AshenPerformCampfireIdle::ExecuteTask(
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
