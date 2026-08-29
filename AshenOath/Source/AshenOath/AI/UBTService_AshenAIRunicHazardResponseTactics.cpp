// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenAIRunicHazardResponseTactics.h"

UBTService_AshenAIRunicHazardResponseTactics::UBTService_AshenAIRunicHazardResponseTactics()
{
	NodeName = TEXT("Ashen AI Runic Hazard Response Tactics");
	Interval = 0.50f;
	RandomDeviation = 0.10f;
	bEvadingTerrainFissure = false;
}

void UBTService_AshenAIRunicHazardResponseTactics::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
