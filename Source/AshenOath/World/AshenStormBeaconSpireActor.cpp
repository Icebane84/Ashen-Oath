// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenStormBeaconSpireActor.h"

AAshenStormBeaconSpireActor::AAshenStormBeaconSpireActor()
{
	PrimaryActorTick.bCanEverTick = false;
	AttractionRadius = 1800.0f;
	bIsSpireHarmonized = false;
}
void AAshenStormBeaconSpireActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenStormBeaconSpireActor::HarmonizeSpire(AActor* InstigatingPlayer)
{
	if (!InstigatingPlayer) return false;
	bIsSpireHarmonized = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenStormBeaconSpireActor: Storm Beacon Spire harmonized with psychic storm harmonics!"));
	return true;
}
