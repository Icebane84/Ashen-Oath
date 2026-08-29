// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenAIForensicWeaknessTactics.h"

UBTService_AshenAIForensicWeaknessTactics::UBTService_AshenAIForensicWeaknessTactics()
{
	NodeName = TEXT("Ashen AI Forensic Weakness Tactics");
	Interval = 0.50f;
	RandomDeviation = 0.10f;
	bTargetingVulnerableGland = false;
}

void UBTService_AshenAIForensicWeaknessTactics::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
