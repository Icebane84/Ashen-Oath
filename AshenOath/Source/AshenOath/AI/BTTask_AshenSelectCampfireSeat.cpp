// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenSelectCampfireSeat.h"
#include "AIController.h"

UBTTask_AshenSelectCampfireSeat::UBTTask_AshenSelectCampfireSeat()
{
	NodeName = TEXT("Ashen Select Campfire Seat");
	DesiredSeating = ECompanionHearthSeating::StandardFireside;
}

EBTNodeResult::Type UBTTask_AshenSelectCampfireSeat::ExecuteTask(
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
