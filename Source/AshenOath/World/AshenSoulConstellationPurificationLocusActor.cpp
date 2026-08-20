// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenSoulConstellationPurificationLocusActor.h"

AAshenSoulConstellationPurificationLocusActor::AAshenSoulConstellationPurificationLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenSoulConstellationPurificationLocusActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenSoulConstellationPurificationLocusActor: Purification locus active."));
}

void AAshenSoulConstellationPurificationLocusActor::IgnitePurificationFlamePillar()
{
	UE_LOG(LogTemp, Warning, TEXT("AAshenSoulConstellationPurificationLocusActor: Radiant white flame pillar ignited!"));
}
