// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenSulfurousSmokeBalmCloudActor.h"

AAshenSulfurousSmokeBalmCloudActor::AAshenSulfurousSmokeBalmCloudActor()
{
	PrimaryActorTick.bCanEverTick = false;
	SmokeRadiusUnits = 800.0f;
}
void AAshenSulfurousSmokeBalmCloudActor::BeginPlay() { Super::BeginPlay(); }

void AAshenSulfurousSmokeBalmCloudActor::SpawnDenseSmokeCloud(FVector SpawnLocation)
{
	SetActorLocation(SpawnLocation);
	UE_LOG(LogTemp, Warning, TEXT("AAshenSulfurousSmokeBalmCloudActor: Dense Grey Sulfurous Smoke Cloud Deployed (Radius: %.1fuu)!"),
		SmokeRadiusUnits);
}
