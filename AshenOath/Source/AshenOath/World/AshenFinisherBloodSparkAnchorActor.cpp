// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenFinisherBloodSparkAnchorActor.h"

AAshenFinisherBloodSparkAnchorActor::AAshenFinisherBloodSparkAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenFinisherBloodSparkAnchorActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenFinisherBloodSparkAnchorActor: Blood spark anchor active."));
}

void AAshenFinisherBloodSparkAnchorActor::SpawnDirectionalBloodSparks(FVector ImpactNormal)
{
	UE_LOG(LogTemp, Log, TEXT("AAshenFinisherBloodSparkAnchorActor: Directional blood sparks spawned along normal (%f, %f, %f)"),
		ImpactNormal.X, ImpactNormal.Y, ImpactNormal.Z);
}
