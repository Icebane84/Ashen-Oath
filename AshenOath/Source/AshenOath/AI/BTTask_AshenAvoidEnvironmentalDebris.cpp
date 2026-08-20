// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenAvoidEnvironmentalDebris.h"
#include "AIController.h"

UBTTask_AshenAvoidEnvironmentalDebris::UBTTask_AshenAvoidEnvironmentalDebris()
{
	NodeName = TEXT("Ashen Avoid Environmental Debris");
	EvadeRadiusUU = 400.0f;
}

EBTNodeResult::Type UBTTask_AshenAvoidEnvironmentalDebris::ExecuteTask(
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
