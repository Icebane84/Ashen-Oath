// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenEvaluatePlayerIntent.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_AshenEvaluatePlayerIntent::UBTTask_AshenEvaluatePlayerIntent()
{
	NodeName = TEXT("Ashen Evaluate Player Intent");
	CompanionId = FName(TEXT("Garrett"));
	ResponseBlackboardKey = FName(TEXT("TacticalResponse"));
}

EBTNodeResult::Type UBTTask_AshenEvaluatePlayerIntent::ExecuteTask(
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
		Blackboard->SetValueAsEnum(ResponseBlackboardKey, static_cast<uint8>(ECompanionTacticalResponse::ShoulderToShoulderCommit));
	}

	return EBTNodeResult::Succeeded;
}
