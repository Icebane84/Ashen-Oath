// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenConsecratedSanctuaryRingActor.h"

AAshenConsecratedSanctuaryRingActor::AAshenConsecratedSanctuaryRingActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenConsecratedSanctuaryRingActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenConsecratedSanctuaryRingActor: Consecrated sanctuary ring actor active for %.1fs."), Duration);
}

void AAshenConsecratedSanctuaryRingActor::DissolveSanctuaryRing()
{
	UE_LOG(LogTemp, Log, TEXT("AAshenConsecratedSanctuaryRingActor: Consecrated sanctuary ring dissolved."));
	Destroy();
}
