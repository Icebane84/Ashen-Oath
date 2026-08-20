// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenVoidShatterRuptureLocusActor.h"

AAshenVoidShatterRuptureLocusActor::AAshenVoidShatterRuptureLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenVoidShatterRuptureLocusActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenVoidShatterRuptureLocusActor: Void rupture locus active for %.1fs."), RuptureLifetime);
}

void AAshenVoidShatterRuptureLocusActor::DissolveRuptureLocus()
{
	UE_LOG(LogTemp, Log, TEXT("AAshenVoidShatterRuptureLocusActor: Void rupture locus dissolved."));
	Destroy();
}
