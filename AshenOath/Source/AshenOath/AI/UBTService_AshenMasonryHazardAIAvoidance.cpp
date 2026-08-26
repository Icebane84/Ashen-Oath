// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenMasonryHazardAIAvoidance.h"

UBTService_AshenMasonryHazardAIAvoidance::UBTService_AshenMasonryHazardAIAvoidance()
{
	NodeName = TEXT("Ashen Masonry Hazard AI Avoidance");
	Interval = 0.25f;
	RandomDeviation = 0.05f;
	EvacuationDistanceBufferUU = 150.0f;
}

void UBTService_AshenMasonryHazardAIAvoidance::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
