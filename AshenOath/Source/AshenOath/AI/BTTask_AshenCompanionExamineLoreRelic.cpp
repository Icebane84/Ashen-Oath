// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenCompanionExamineLoreRelic.h"
#include "AIController.h"

UBTTask_AshenCompanionExamineLoreRelic::UBTTask_AshenCompanionExamineLoreRelic()
{
	NodeName = TEXT("Ashen Companion Examine Lore Relic");
	RelicToInspect = NAME_None;
}

EBTNodeResult::Type UBTTask_AshenCompanionExamineLoreRelic::ExecuteTask(
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
