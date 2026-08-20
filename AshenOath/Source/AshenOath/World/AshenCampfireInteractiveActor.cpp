// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 611: Ashen Campfire Interactive Actor

#include "AshenCampfireInteractiveActor.h"

AAshenCampfireInteractiveActor::AAshenCampfireInteractiveActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsLit = false;
	CampfireID = FName(TEXT("Campfire.DefaultSanctuary"));
}

void AAshenCampfireInteractiveActor::IgniteCampfire(float HeatRadius)
{
	bIsLit = true;
	OnCampfireLit.Broadcast(CampfireID, HeatRadius);

	UE_LOG(LogTemp, Warning, TEXT("AAshenCampfireInteractiveActor: CAMPFIRE IGNITED -> ID '%s' (Heat Radius: %.0f units)."),
		*CampfireID.ToString(), HeatRadius);
}
