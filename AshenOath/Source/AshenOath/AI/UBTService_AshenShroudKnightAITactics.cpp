// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenShroudKnightAITactics.h"

UBTService_AshenShroudKnightAITactics::UBTService_AshenShroudKnightAITactics()
{
	NodeName = TEXT("Ashen Shroud Knight AI Tactics");
	Interval = 0.20f;
	RandomDeviation = 0.05f;
	GlitchLurchIntervalSeconds = 1.5f;
}

void UBTService_AshenShroudKnightAITactics::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
