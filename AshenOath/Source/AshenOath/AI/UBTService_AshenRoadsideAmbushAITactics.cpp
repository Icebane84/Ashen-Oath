// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenRoadsideAmbushAITactics.h"

UBTService_AshenRoadsideAmbushAITactics::UBTService_AshenRoadsideAmbushAITactics()
{
	NodeName = TEXT("Ashen Roadside Ambush AI Tactics");
	Interval = 0.25f;
	RandomDeviation = 0.05f;
	PincerEncirclementAngle = 60.0f;
}

void UBTService_AshenRoadsideAmbushAITactics::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
