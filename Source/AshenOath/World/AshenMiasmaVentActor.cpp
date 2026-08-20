// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenMiasmaVentActor.h"

AAshenMiasmaVentActor::AAshenMiasmaVentActor()
{
	PrimaryActorTick.bCanEverTick = false;
	PlumeRadius = 600.0f;
	bIsVentActive = true;
}
void AAshenMiasmaVentActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenMiasmaVentActor::SealVent(AActor* InstigatingPlayer)
{
	if (!InstigatingPlayer) return false;
	bIsVentActive = false;
	UE_LOG(LogTemp, Warning, TEXT("AAshenMiasmaVentActor: Miasma Vent sealed by Player!"));
	return true;
}
