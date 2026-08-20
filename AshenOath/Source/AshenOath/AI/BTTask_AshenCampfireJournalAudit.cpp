// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenCampfireJournalAudit.h"
#include "AIController.h"

UBTTask_AshenCampfireJournalAudit::UBTTask_AshenCampfireJournalAudit()
{
	NodeName = TEXT("Ashen Campfire Journal Audit");
	CompanionAuthor = EMarginaliaAuthor::Garrett;
}

EBTNodeResult::Type UBTTask_AshenCampfireJournalAudit::ExecuteTask(
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
