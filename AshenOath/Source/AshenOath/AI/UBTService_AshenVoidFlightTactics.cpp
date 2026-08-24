// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenVoidFlightTactics.h"

UBTService_AshenVoidFlightTactics::UBTService_AshenVoidFlightTactics()
{
	NodeName = TEXT("Ashen Void Flight Tactics");
	Interval = 0.25f;
	RandomDeviation = 0.05f;
	FlightHoverHeightUU = 300.0f;
}

void UBTService_AshenVoidFlightTactics::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
