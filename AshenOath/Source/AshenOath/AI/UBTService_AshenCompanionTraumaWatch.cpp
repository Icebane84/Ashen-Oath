// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenCompanionTraumaWatch.h"
#include "AIController.h"

UBTService_AshenCompanionTraumaWatch::UBTService_AshenCompanionTraumaWatch()
{
	NodeName = TEXT("Companion Trauma Watch");
	Interval = 0.5f;
	RandomDeviation = 0.1f;
	CrisisThreshold = 0.50f;
}

void UBTService_AshenCompanionTraumaWatch::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
