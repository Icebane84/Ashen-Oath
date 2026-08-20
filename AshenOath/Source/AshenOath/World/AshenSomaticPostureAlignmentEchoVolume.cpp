// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenSomaticPostureAlignmentEchoVolume.h"

AAshenSomaticPostureAlignmentEchoVolume::AAshenSomaticPostureAlignmentEchoVolume()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenSomaticPostureAlignmentEchoVolume::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenSomaticPostureAlignmentEchoVolume: Somatic Posture Alignment Echo Volume initialized (Intensity: %f)."), PostureAlignmentEchoIntensity);
}

void AAshenSomaticPostureAlignmentEchoVolume::ApplyPostureAlignmentEchoToActor(AActor* TargetActor)
{
	if (!TargetActor) return;
	UE_LOG(LogTemp, Log, TEXT("AAshenSomaticPostureAlignmentEchoVolume: Applied posture alignment echo to %s"), *TargetActor->GetName());
}
