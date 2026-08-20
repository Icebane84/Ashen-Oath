// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenFinisherCinematicCameraActor.h"

AAshenFinisherCinematicCameraActor::AAshenFinisherCinematicCameraActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenFinisherCinematicCameraActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenFinisherCinematicCameraActor: Finisher camera actor initialized."));
}

void AAshenFinisherCinematicCameraActor::FrameFinisherCinematic(FVector TargetLocation, float Duration)
{
	UE_LOG(LogTemp, Warning, TEXT("AAshenFinisherCinematicCameraActor: Cinematic slow-mo camera framed at (%f, %f, %f) for %.2fs"),
		TargetLocation.X, TargetLocation.Y, TargetLocation.Z, Duration);
}
