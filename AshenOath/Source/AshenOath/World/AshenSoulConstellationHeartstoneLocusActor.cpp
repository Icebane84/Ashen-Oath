// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenSoulConstellationHeartstoneLocusActor.h"

AAshenSoulConstellationHeartstoneLocusActor::AAshenSoulConstellationHeartstoneLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenSoulConstellationHeartstoneLocusActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenSoulConstellationHeartstoneLocusActor: Heartstone ritual locus initialized (Radius=%f)."), HeartstoneResonanceRadius);
}

bool AAshenSoulConstellationHeartstoneLocusActor::TriggerHeartstoneIdentityCompilation()
{
	UE_LOG(LogTemp, Warning, TEXT("AAshenSoulConstellationHeartstoneLocusActor: Heartstone invoked — CompileIdentity() ritual triggered on Soul Constellation Kernel."));
	return true;
}
