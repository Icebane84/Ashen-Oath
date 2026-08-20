// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 759: Ashen Oath Campfire Rest Area Actor

#include "AshenAshenOathCampfireRestAreaActor.h"

AAshenAshenOathCampfireRestAreaActor::AAshenAshenOathCampfireRestAreaActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsCampfireLit = true;
}

void AAshenAshenOathCampfireRestAreaActor::TriggerCampfireRest()
{
	OnCampfireRestTriggered.Broadcast(GetActorLocation(), true);

	UE_LOG(LogTemp, Warning, TEXT("AAshenAshenOathCampfireRestAreaActor: CAMPFIRE REST TRIGGERED -> Location: (%s) | Party Health & Willpower Restored."),
		*GetActorLocation().ToString());
}
