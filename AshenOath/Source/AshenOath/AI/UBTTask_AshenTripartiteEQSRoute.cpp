// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTTask_AshenTripartiteEQSRoute.h"
#include "AIController.h"

UBTTask_AshenTripartiteEQSRoute::UBTTask_AshenTripartiteEQSRoute()
{
	NodeName = TEXT("Tripartite EQS Route");
	TargetMode = ETripartiteBehaviorMode::CombatEngagement;
}

EBTNodeResult::Type UBTTask_AshenTripartiteEQSRoute::ExecuteTask(
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
