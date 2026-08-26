// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/UBTService_AshenCompanionCampfireSocialAI.h"

UBTService_AshenCompanionCampfireSocialAI::UBTService_AshenCompanionCampfireSocialAI()
{
	NodeName = TEXT("Ashen Companion Campfire Social AI");
	Interval = 0.50f;
	RandomDeviation = 0.10f;
	CampfireSocialRadiusUU = 250.0f;
}

void UBTService_AshenCompanionCampfireSocialAI::TickNode(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
