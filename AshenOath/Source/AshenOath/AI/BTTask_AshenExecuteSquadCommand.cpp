// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenExecuteSquadCommand.h"
#include "AIController.h"

UBTTask_AshenExecuteSquadCommand::UBTTask_AshenExecuteSquadCommand()
{
	NodeName = TEXT("Ashen Execute Squad Command");
	CommandToExecute = ETacticalCommandType::GarrettWireSnare;
}

EBTNodeResult::Type UBTTask_AshenExecuteSquadCommand::ExecuteTask(
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
