// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenExecuteComboFollowup.h"
#include "AIController.h"

UBTTask_AshenExecuteComboFollowup::UBTTask_AshenExecuteComboFollowup()
{
	NodeName = TEXT("Ashen Execute Combo Followup");
	MaxComboDistanceUU = 800.0f;
}

EBTNodeResult::Type UBTTask_AshenExecuteComboFollowup::ExecuteTask(
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
