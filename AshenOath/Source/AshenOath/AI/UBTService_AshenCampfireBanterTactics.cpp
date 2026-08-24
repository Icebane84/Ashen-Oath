// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenCampfireBanterTactics.h"

UBTService_AshenCampfireBanterTactics::UBTService_AshenCampfireBanterTactics()
{
	NodeName = TEXT("Ashen Campfire Banter Tactics");
	Interval = 0.20f;
	RandomDeviation = 0.05f;
	CampfireGazeProximityUU = 300.0f;
}

void UBTService_AshenCampfireBanterTactics::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
