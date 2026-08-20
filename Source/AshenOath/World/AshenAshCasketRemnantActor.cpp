// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenAshCasketRemnantActor.h"

AAshenAshCasketRemnantActor::AAshenAshCasketRemnantActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsHarvested = false;
}
void AAshenAshCasketRemnantActor::BeginPlay() { Super::BeginPlay(); }

int32 AAshenAshCasketRemnantActor::HarvestFrozenBasalt(AActor* InstigatingPlayer)
{
	if (!InstigatingPlayer || bIsHarvested) return 0;
	bIsHarvested = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenAshCasketRemnantActor: Harvested 3x Frozen Basalt Shards from Ash-Casket Remnant."));
	return 3;
}
