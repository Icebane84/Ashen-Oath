// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenMiasmaDispersalVolumeActor.h"

AAshenMiasmaDispersalVolumeActor::AAshenMiasmaDispersalVolumeActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenMiasmaDispersalVolumeActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenMiasmaDispersalVolumeActor: Miasma dispersal volume initialized."));
}

void AAshenMiasmaDispersalVolumeActor::DisperseMiasma(float LightIntensity)
{
	MiasmaDensity = FMath::Clamp(MiasmaDensity - (0.25f * LightIntensity), 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("AAshenMiasmaDispersalVolumeActor: Miasma density reduced to %.2f by alchemical light beam."), MiasmaDensity);
}
