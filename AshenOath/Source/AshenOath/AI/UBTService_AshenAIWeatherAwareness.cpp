// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenAIWeatherAwareness.h"

UBTService_AshenAIWeatherAwareness::UBTService_AshenAIWeatherAwareness()
{
	NodeName = TEXT("Ashen AI Weather Awareness");
	Interval = 0.50f;
	RandomDeviation = 0.10f;
	MaxShelterSearchRadiusUU = 1500.0f;
}

void UBTService_AshenAIWeatherAwareness::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
