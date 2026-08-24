// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenCompanionHuddleWatch.h"

UBTService_AshenCompanionHuddleWatch::UBTService_AshenCompanionHuddleWatch()
{
	NodeName = TEXT("Companion Huddle Watch");
	Interval = 0.5f;
	RandomDeviation = 0.1f;
	MaxHuddleDistanceUU = 350.0f;
}

void UBTService_AshenCompanionHuddleWatch::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
