// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenBossSelectPhaseAction.h"
#include "AIController.h"

UBTTask_AshenBossSelectPhaseAction::UBTTask_AshenBossSelectPhaseAction()
{
	NodeName = TEXT("Ashen Boss Select Phase Action");
	TargetPhase = EBossEncounterPhase::Phase1_Guardian;
}

EBTNodeResult::Type UBTTask_AshenBossSelectPhaseAction::ExecuteTask(
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
