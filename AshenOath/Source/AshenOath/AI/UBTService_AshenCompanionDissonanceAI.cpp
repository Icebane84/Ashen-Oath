// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenCompanionDissonanceAI.h"

UBTService_AshenCompanionDissonanceAI::UBTService_AshenCompanionDissonanceAI()
{
	NodeName = TEXT("Ashen Companion Dissonance AI");
	Interval = 0.50f;
	RandomDeviation = 0.10f;
	AssistHesitationDelaySeconds = 0.0f;
}

void UBTService_AshenCompanionDissonanceAI::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
