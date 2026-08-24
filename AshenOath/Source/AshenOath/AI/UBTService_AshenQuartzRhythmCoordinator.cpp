// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenQuartzRhythmCoordinator.h"

UBTService_AshenQuartzRhythmCoordinator::UBTService_AshenQuartzRhythmCoordinator()
{
	NodeName = TEXT("Ashen Quartz Rhythm Coordinator");
	Interval = 0.5217f; // Exactly 1 beat at 115 BPM (60 / 115 = 0.5217s)
	RandomDeviation = 0.01f;
	TargetBPM = 115.0f;
}

void UBTService_AshenQuartzRhythmCoordinator::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
