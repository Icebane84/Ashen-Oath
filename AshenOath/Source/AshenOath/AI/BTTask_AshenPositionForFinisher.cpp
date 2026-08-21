// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenPositionForFinisher.h"
#include "AIController.h"

UBTTask_AshenPositionForFinisher::UBTTask_AshenPositionForFinisher()
{
	NodeName = TEXT("Ashen Position For Finisher");
	FinisherArcOffsetAngle = 120.0f;
}

EBTNodeResult::Type UBTTask_AshenPositionForFinisher::ExecuteTask(
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
