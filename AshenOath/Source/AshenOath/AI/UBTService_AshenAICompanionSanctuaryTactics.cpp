// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenAICompanionSanctuaryTactics.h"

UBTService_AshenAICompanionSanctuaryTactics::UBTService_AshenAICompanionSanctuaryTactics()
{
	NodeName = TEXT("Ashen AI Companion Sanctuary Tactics");
	Interval = 0.50f;
	RandomDeviation = 0.10f;
	bInSanctuaryRestState = false;
}

void UBTService_AshenAICompanionSanctuaryTactics::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
