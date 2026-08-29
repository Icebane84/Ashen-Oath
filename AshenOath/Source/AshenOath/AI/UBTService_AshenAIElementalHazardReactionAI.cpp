// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenAIElementalHazardReactionAI.h"

UBTService_AshenAIElementalHazardReactionAI::UBTService_AshenAIElementalHazardReactionAI()
{
	NodeName = TEXT("Ashen AI Elemental Hazard Reaction AI");
	Interval = 0.40f;
	RandomDeviation = 0.10f;
	bEvadingThermalBlast = false;
}

void UBTService_AshenAIElementalHazardReactionAI::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
