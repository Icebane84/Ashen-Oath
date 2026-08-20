// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenSovereignPhoenixAscensionLocusActor.h"

AAshenSovereignPhoenixAscensionLocusActor::AAshenSovereignPhoenixAscensionLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenSovereignPhoenixAscensionLocusActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AAshenSovereignPhoenixAscensionLocusActor: Sovereign Phoenix Ascension Locus initialized with intensity %f."), WhiteFlameLuminescenceIntensity);
}

void AAshenSovereignPhoenixAscensionLocusActor::TriggerPhoenixAscensionPulse()
{
	if (!bSovereignLocusConsecrated) return;
	UE_LOG(LogTemp, Warning, TEXT("AAshenSovereignPhoenixAscensionLocusActor: Triggered Sovereign Phoenix Ascension luminescence pulse across map bounds!"));
}
