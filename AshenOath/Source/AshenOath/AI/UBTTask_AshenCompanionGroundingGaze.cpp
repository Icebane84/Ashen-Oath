// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTTask_AshenCompanionGroundingGaze.h"
#include "AIController.h"

UBTTask_AshenCompanionGroundingGaze::UBTTask_AshenCompanionGroundingGaze()
{
	NodeName = TEXT("Companion Grounding Gaze");
	TargetThreatKey = FName(TEXT("PerceivedThreat"));
}

EBTNodeResult::Type UBTTask_AshenCompanionGroundingGaze::ExecuteTask(
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
