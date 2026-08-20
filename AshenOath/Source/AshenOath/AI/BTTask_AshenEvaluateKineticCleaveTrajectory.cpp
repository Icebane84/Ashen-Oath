// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenEvaluateKineticCleaveTrajectory.h"
#include "AIController.h"

UBTTask_AshenEvaluateKineticCleaveTrajectory::UBTTask_AshenEvaluateKineticCleaveTrajectory()
{
	NodeName = TEXT("Ashen Evaluate Kinetic Cleave Trajectory");
	CleaveSweepRadiusUU = 350.0f;
}

EBTNodeResult::Type UBTTask_AshenEvaluateKineticCleaveTrajectory::ExecuteTask(
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
