// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenCompanionSanitySupportAI.h"

UBTService_AshenCompanionSanitySupportAI::UBTService_AshenCompanionSanitySupportAI()
{
	NodeName = TEXT("Ashen Companion Sanity Support AI");
	Interval = 0.50f;
	RandomDeviation = 0.10f;
	CriticalSanityThreshold = 35.0f;
}

void UBTService_AshenCompanionSanitySupportAI::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
