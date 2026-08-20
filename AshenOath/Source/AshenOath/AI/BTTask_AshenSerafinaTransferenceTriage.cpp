// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenSerafinaTransferenceTriage.h"
#include "AIController.h"

UBTTask_AshenSerafinaTransferenceTriage::UBTTask_AshenSerafinaTransferenceTriage()
{
	NodeName = TEXT("Ashen Serafina Transference Triage");
	MaxSafeBurnoutThreshold = 80.0f;
}

EBTNodeResult::Type UBTTask_AshenSerafinaTransferenceTriage::ExecuteTask(
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
