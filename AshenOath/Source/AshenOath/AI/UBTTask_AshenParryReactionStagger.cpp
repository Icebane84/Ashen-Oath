// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTTask_AshenParryReactionStagger.h"
#include "AIController.h"

UBTTask_AshenParryReactionStagger::UBTTask_AshenParryReactionStagger()
{
	NodeName = TEXT("Parry Reaction Stagger");
	StaggerDurationSeconds = 1.25f;
}

EBTNodeResult::Type UBTTask_AshenParryReactionStagger::ExecuteTask(
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
