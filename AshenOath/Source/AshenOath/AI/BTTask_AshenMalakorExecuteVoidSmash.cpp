// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenMalakorExecuteVoidSmash.h"
#include "AIController.h"

UBTTask_AshenMalakorExecuteVoidSmash::UBTTask_AshenMalakorExecuteVoidSmash()
{
	NodeName = TEXT("Ashen Malakor Execute Void Smash");
	WindupDurationSeconds = 1.20f;
}

EBTNodeResult::Type UBTTask_AshenMalakorExecuteVoidSmash::ExecuteTask(
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
