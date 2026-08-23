// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTTask_AshenGarrettWaystationTactics.h"
#include "AIController.h"

UBTTask_AshenGarrettWaystationTactics::UBTTask_AshenGarrettWaystationTactics()
{
	NodeName = TEXT("Garrett Waystation Tactics");
	DesiredTactic = EGarrettDualWieldBenchmarkResponse::TwinBladeXLockDeflect;
}

EBTNodeResult::Type UBTTask_AshenGarrettWaystationTactics::ExecuteTask(
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
