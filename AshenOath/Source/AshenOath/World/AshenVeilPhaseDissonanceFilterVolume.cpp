// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenVeilPhaseDissonanceFilterVolume.h"

AAshenVeilPhaseDissonanceFilterVolume::AAshenVeilPhaseDissonanceFilterVolume()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenVeilPhaseDissonanceFilterVolume::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenVeilPhaseDissonanceFilterVolume: Veil Phase Filter Volume initialized (Intensity: %f)."), VeilPhaseFilterIntensity);
}

void AAshenVeilPhaseDissonanceFilterVolume::ApplyVeilPhaseFilterToActor(AActor* TargetActor)
{
	if (!TargetActor) return;
	UE_LOG(LogTemp, Log, TEXT("AAshenVeilPhaseDissonanceFilterVolume: Applied veil phase filter to %s"), *TargetActor->GetName());
}
