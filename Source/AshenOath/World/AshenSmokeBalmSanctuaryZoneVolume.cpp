// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 707: Ashen Smoke Balm Sanctuary Zone Volume

#include "AshenSmokeBalmSanctuaryZoneVolume.h"

AAshenSmokeBalmSanctuaryZoneVolume::AAshenSmokeBalmSanctuaryZoneVolume()
{
	PrimaryActorTick.bCanEverTick = false;
	ActiveConcealmentRating = 90.0f;
}

void AAshenSmokeBalmSanctuaryZoneVolume::ApplyConcealmentToActor(AActor* TargetActor)
{
	if (!TargetActor) return;

	OnZoneEntered.Broadcast(TargetActor, ActiveConcealmentRating);

	UE_LOG(LogTemp, Warning, TEXT("AAshenSmokeBalmSanctuaryZoneVolume: SMOKE BALM CONCEALMENT APPLIED -> Actor '%s' | Concealment: %.0f%%."),
		*TargetActor->GetName(), ActiveConcealmentRating);
}
