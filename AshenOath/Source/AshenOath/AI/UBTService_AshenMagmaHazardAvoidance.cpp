// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenMagmaHazardAvoidance.h"

UBTService_AshenMagmaHazardAvoidance::UBTService_AshenMagmaHazardAvoidance()
{
	NodeName = TEXT("Ashen Magma Hazard Avoidance");
	Interval = 0.25f;
	RandomDeviation = 0.05f;
	MagmaEvacuateRadiusUU = 450.0f;
}

void UBTService_AshenMagmaHazardAvoidance::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
