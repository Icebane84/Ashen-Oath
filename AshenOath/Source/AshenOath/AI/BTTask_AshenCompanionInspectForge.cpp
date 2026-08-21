// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenCompanionInspectForge.h"
#include "AIController.h"

UBTTask_AshenCompanionInspectForge::UBTTask_AshenCompanionInspectForge()
{
	NodeName = TEXT("Ashen Companion Inspect Forge");
	InspectionDurationSeconds = 3.0f;
}

EBTNodeResult::Type UBTTask_AshenCompanionInspectForge::ExecuteTask(
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
