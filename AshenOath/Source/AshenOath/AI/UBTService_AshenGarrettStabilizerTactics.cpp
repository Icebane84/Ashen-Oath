// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenGarrettStabilizerTactics.h"

UBTService_AshenGarrettStabilizerTactics::UBTService_AshenGarrettStabilizerTactics()
{
	NodeName = TEXT("Ashen Garrett Stabilizer Tactics");
	Interval = 0.15f;
	RandomDeviation = 0.02f;
	StabilizationThreshold01 = 0.70f;
}

void UBTService_AshenGarrettStabilizerTactics::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
