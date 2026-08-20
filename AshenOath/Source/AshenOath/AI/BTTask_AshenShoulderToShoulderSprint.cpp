// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenShoulderToShoulderSprint.h"
#include "AIController.h"

UBTTask_AshenShoulderToShoulderSprint::UBTTask_AshenShoulderToShoulderSprint()
{
	NodeName = TEXT("Ashen Shoulder-To-Shoulder Sprint");
	TargetOffsetDistance = 200.0f;
}

EBTNodeResult::Type UBTTask_AshenShoulderToShoulderSprint::ExecuteTask(
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
