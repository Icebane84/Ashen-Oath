// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenCompanionMarginaliaQuery.h"
#include "AIController.h"

UBTTask_AshenCompanionMarginaliaQuery::UBTTask_AshenCompanionMarginaliaQuery()
{
	NodeName = TEXT("Ashen Companion Marginalia Query");
	CompanionName = FName(TEXT("Garrett"));
}

EBTNodeResult::Type UBTTask_AshenCompanionMarginaliaQuery::ExecuteTask(
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
