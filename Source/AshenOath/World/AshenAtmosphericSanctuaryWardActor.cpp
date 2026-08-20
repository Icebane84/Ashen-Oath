// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenAtmosphericSanctuaryWardActor.h"

AAshenAtmosphericSanctuaryWardActor::AAshenAtmosphericSanctuaryWardActor()
{
	PrimaryActorTick.bCanEverTick = false;
	PurifiedZoneRadius = 1200.0f;
	bIsWardActivated = false;
}
void AAshenAtmosphericSanctuaryWardActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenAtmosphericSanctuaryWardActor::ActivateWard(AActor* InstigatingPlayer)
{
	if (!InstigatingPlayer) return false;
	bIsWardActivated = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenAtmosphericSanctuaryWardActor: Sanctuary Ward activated (Purified Radius: %.1fuu)!"),
		PurifiedZoneRadius);
	return true;
}
