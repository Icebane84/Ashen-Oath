// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTTask_AshenDynamicDetourRoute.h"
#include "AIController.h"

UBTTask_AshenDynamicDetourRoute::UBTTask_AshenDynamicDetourRoute()
{
	NodeName = TEXT("Chaos Dynamic Detour Route");
	DetourSearchRadiusUU = 1200.0f;
}

EBTNodeResult::Type UBTTask_AshenDynamicDetourRoute::ExecuteTask(
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
