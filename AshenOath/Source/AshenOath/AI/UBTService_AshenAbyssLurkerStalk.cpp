// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenAbyssLurkerStalk.h"

UBTService_AshenAbyssLurkerStalk::UBTService_AshenAbyssLurkerStalk()
{
	NodeName = TEXT("Ashen Abyss Lurker Stalk");
	Interval = 0.25f;
	RandomDeviation = 0.05f;
	StalkingDistanceThresholdUU = 600.0f;
}

void UBTService_AshenAbyssLurkerStalk::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
