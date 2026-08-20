// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenSmokeCloudVolumeActor.h"

AAshenSmokeCloudVolumeActor::AAshenSmokeCloudVolumeActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenSmokeCloudVolumeActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenSmokeCloudVolumeActor: Smoke cloud volume active for %.1fs."), CloudLifetime);
}

void AAshenSmokeCloudVolumeActor::DissipateSmokeCloud()
{
	UE_LOG(LogTemp, Log, TEXT("AAshenSmokeCloudVolumeActor: Smoke cloud dissipated cleanly."));
	Destroy();
}
