// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenVeilPhaseDissonanceVolume.h"

AAshenVeilPhaseDissonanceVolume::AAshenVeilPhaseDissonanceVolume()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenVeilPhaseDissonanceVolume::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenVeilPhaseDissonanceVolume: Veil Phase Dissonance Volume initialized (Intensity: %f)."), VeilDissonanceIntensity);
}

void AAshenVeilPhaseDissonanceVolume::ApplyVeilPhaseDistortionToActor(AActor* TargetActor)
{
	if (!TargetActor) return;
	UE_LOG(LogTemp, Log, TEXT("AAshenVeilPhaseDissonanceVolume: Applied veil phase distortion to %s"), *TargetActor->GetName());
}
