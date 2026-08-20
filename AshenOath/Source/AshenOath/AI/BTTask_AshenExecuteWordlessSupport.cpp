// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenExecuteWordlessSupport.h"
#include "AIController.h"

UBTTask_AshenExecuteWordlessSupport::UBTTask_AshenExecuteWordlessSupport()
{
	NodeName = TEXT("Ashen Execute Wordless Support");
	ObstacleLocationBlackboardKey = FName(TEXT("TargetObstacleLocation"));
}

EBTNodeResult::Type UBTTask_AshenExecuteWordlessSupport::ExecuteTask(
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
