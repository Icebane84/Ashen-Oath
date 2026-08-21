// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenGhoulPathfindingPanic.h"
#include "AIController.h"

UBTTask_AshenGhoulPathfindingPanic::UBTTask_AshenGhoulPathfindingPanic()
{
	NodeName = TEXT("Ashen Ghoul Pathfinding Panic");
	PanicFleeSpeed = 450.0f;
}

EBTNodeResult::Type UBTTask_AshenGhoulPathfindingPanic::ExecuteTask(
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
