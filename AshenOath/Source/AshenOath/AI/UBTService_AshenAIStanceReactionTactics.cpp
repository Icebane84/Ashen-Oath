// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenAIStanceReactionTactics.h"

UBTService_AshenAIStanceReactionTactics::UBTService_AshenAIStanceReactionTactics()
{
	NodeName = TEXT("Ashen AI Stance Reaction Tactics");
	Interval = 0.40f;
	RandomDeviation = 0.10f;
	bBracingAgainstHeavyCleave = false;
}

void UBTService_AshenAIStanceReactionTactics::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
