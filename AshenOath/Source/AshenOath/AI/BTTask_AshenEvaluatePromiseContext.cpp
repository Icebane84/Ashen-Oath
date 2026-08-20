// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenEvaluatePromiseContext.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_AshenEvaluatePromiseContext::UBTTask_AshenEvaluatePromiseContext()
{
	NodeName = TEXT("Ashen Evaluate Promise Context");
	HasActivePromiseBlackboardKey = FName(TEXT("bHasActivePromise"));
}

EBTNodeResult::Type UBTTask_AshenEvaluatePromiseContext::ExecuteTask(
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
		Blackboard->SetValueAsBool(HasActivePromiseBlackboardKey, true);
	}

	return EBTNodeResult::Succeeded;
}
