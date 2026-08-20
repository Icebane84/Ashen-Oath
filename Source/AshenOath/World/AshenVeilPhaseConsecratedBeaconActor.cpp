// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenVeilPhaseConsecratedBeaconActor.h"

AAshenVeilPhaseConsecratedBeaconActor::AAshenVeilPhaseConsecratedBeaconActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenVeilPhaseConsecratedBeaconActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenVeilPhaseConsecratedBeaconActor: Veil Phase Consecrated Beacon Actor initialized."));
}

bool AAshenVeilPhaseConsecratedBeaconActor::ActivateVeilPhaseBeacon()
{
	if (!bBeaconActive) return false;
	UE_LOG(LogTemp, Log, TEXT("AAshenVeilPhaseConsecratedBeaconActor: Veil phase beacon activated (Stabilization radius: %f)."), StabilizationRadius);
	return true;
}
