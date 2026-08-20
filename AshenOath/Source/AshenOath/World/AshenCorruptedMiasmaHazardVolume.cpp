// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenCorruptedMiasmaHazardVolume.h"

AAshenCorruptedMiasmaHazardVolume::AAshenCorruptedMiasmaHazardVolume()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenCorruptedMiasmaHazardVolume::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenCorruptedMiasmaHazardVolume: Miasma hazard volume active with DPS %f."), MiasmaCorruptionDPS);
}

void AAshenCorruptedMiasmaHazardVolume::ApplyMiasmaCorruptionToActor(AActor* TargetActor, float DeltaTime)
{
	if (!TargetActor) return;
	UE_LOG(LogTemp, Verbose, TEXT("AAshenCorruptedMiasmaHazardVolume: Applying %f miasma damage to %s"), MiasmaCorruptionDPS * DeltaTime, *TargetActor->GetName());
}
