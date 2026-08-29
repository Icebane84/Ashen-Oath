// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenAIPanicOnSeveranceWitness.h"

UBTService_AshenAIPanicOnSeveranceWitness::UBTService_AshenAIPanicOnSeveranceWitness()
{
	NodeName = TEXT("Ashen AI Panic On Severance Witness");
	Interval = 0.50f;
	RandomDeviation = 0.10f;
	PanicWitnessRadiusUU = 800.0f;
	bInPanickedState = false;
}

void UBTService_AshenAIPanicOnSeveranceWitness::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
