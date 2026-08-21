// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenCompanionRespondToCrisis.h"
#include "AIController.h"

UBTTask_AshenCompanionRespondToCrisis::UBTTask_AshenCompanionRespondToCrisis()
{
	NodeName = TEXT("Ashen Companion Respond To Crisis");
	bProvideCoveringFire = true;
}

EBTNodeResult::Type UBTTask_AshenCompanionRespondToCrisis::ExecuteTask(
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
