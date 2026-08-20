// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenEnforcePromiseLoyalty.h"
#include "AIController.h"

UBTTask_AshenEnforcePromiseLoyalty::UBTTask_AshenEnforcePromiseLoyalty()
{
	NodeName = TEXT("Ashen Enforce Promise Loyalty");
	EnforcedSpacingUU = 200.0f;
}

EBTNodeResult::Type UBTTask_AshenEnforcePromiseLoyalty::ExecuteTask(
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
