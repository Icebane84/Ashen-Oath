// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UAshenStateTreeTask_GarrettDeployTrap.h"
#include "AIController.h"

UUAshenStateTreeTask_GarrettDeployTrap::UUAshenStateTreeTask_GarrettDeployTrap()
{
	NodeName = TEXT("Garrett Deploy Trap");
	TrapToDeploy = EGarrettTrapType::TensionWireSnare;
}

EBTNodeResult::Type UUAshenStateTreeTask_GarrettDeployTrap::ExecuteTask(
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
