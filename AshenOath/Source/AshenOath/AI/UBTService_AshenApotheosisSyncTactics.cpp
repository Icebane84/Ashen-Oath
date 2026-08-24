// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenApotheosisSyncTactics.h"

UBTService_AshenApotheosisSyncTactics::UBTService_AshenApotheosisSyncTactics()
{
	NodeName = TEXT("Ashen Apotheosis Sync Tactics");
	Interval = 0.15f;
	RandomDeviation = 0.02f;
	FlankingSeparationAngleDeg = 120.0f;
}

void UBTService_AshenApotheosisSyncTactics::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
