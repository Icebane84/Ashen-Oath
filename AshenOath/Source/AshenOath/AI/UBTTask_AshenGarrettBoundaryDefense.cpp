// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTTask_AshenGarrettBoundaryDefense.h"
#include "AIController.h"

UBTTask_AshenGarrettBoundaryDefense::UBTTask_AshenGarrettBoundaryDefense()
{
	NodeName = TEXT("Garrett Boundary Defense");
	GuardRadiusCentimeters = 400.0f;
}

EBTNodeResult::Type UBTTask_AshenGarrettBoundaryDefense::ExecuteTask(
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
