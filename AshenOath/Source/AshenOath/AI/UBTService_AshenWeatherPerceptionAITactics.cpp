// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenWeatherPerceptionAITactics.h"

UBTService_AshenWeatherPerceptionAITactics::UBTService_AshenWeatherPerceptionAITactics()
{
	NodeName = TEXT("Ashen Weather Perception & Pincer Tactics");
	Interval = 0.50f;
	RandomDeviation = 0.10f;
	CurrentPincerState = EAIPincerManeuverState::DirectApproach;
}

void UBTService_AshenWeatherPerceptionAITactics::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
