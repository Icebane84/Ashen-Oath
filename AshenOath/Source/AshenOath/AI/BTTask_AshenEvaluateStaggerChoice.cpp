// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenEvaluateStaggerChoice.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Companions/AshenTransferenceBurnoutTypes.h"

UBTTask_AshenEvaluateStaggerChoice::UBTTask_AshenEvaluateStaggerChoice()
{
	NodeName = TEXT("Ashen Evaluate Stagger Choice");
	CompanionId = FName(TEXT("Garrett"));
	StaggerChoiceBlackboardKey = FName(TEXT("SuggestedStaggerChoice"));
}

EBTNodeResult::Type UBTTask_AshenEvaluateStaggerChoice::ExecuteTask(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory)
{
	AAIController* AICon = OwnerComp.GetAIOwner();
	if (!AICon)
	{
		return EBTNodeResult::Failed;
	}

	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	if (Blackboard)
	{
		const uint8 DefaultVal = (CompanionId == FName(TEXT("Serafina"))) 
			? static_cast<uint8>(EFoeStaggerResolutionChoice::MercifulBinding)
			: static_cast<uint8>(EFoeStaggerResolutionChoice::RuthlessExecution);

		Blackboard->SetValueAsEnum(StaggerChoiceBlackboardKey, DefaultVal);
	}

	return EBTNodeResult::Succeeded;
}
