// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenAIPoiseBreakPunishAI.h"

UBTService_AshenAIPoiseBreakPunishAI::UBTService_AshenAIPoiseBreakPunishAI()
{
	NodeName = TEXT("Ashen AI Poise Break Punish AI");
	Interval = 0.25f;
	RandomDeviation = 0.05f;
	PunishGapCloseSpeedMultiplier = 1.35f;
}

void UBTService_AshenAIPoiseBreakPunishAI::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
