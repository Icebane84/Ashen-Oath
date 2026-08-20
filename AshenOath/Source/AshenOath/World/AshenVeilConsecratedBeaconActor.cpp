// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenVeilConsecratedBeaconActor.h"

AAshenVeilConsecratedBeaconActor::AAshenVeilConsecratedBeaconActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenVeilConsecratedBeaconActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenVeilConsecratedBeaconActor: Veil Consecrated Beacon Actor initialized."));
}

bool AAshenVeilConsecratedBeaconActor::ActivateConsecratedBeacon()
{
	if (!bBeaconActive) return false;
	UE_LOG(LogTemp, Log, TEXT("AAshenVeilConsecratedBeaconActor: Consecrated beacon activated (Stabilization radius: %f)."), StabilizationRadius);
	return true;
}
