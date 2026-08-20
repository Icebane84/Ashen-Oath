// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenPhantomMirageFoeActor.h"

AAshenPhantomMirageFoeActor::AAshenPhantomMirageFoeActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenPhantomMirageFoeActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenPhantomMirageFoeActor: Phantom mirage foe spawned into world."));
}

void AAshenPhantomMirageFoeActor::DissolveMirageOnHit()
{
	UE_LOG(LogTemp, Warning, TEXT("AAshenPhantomMirageFoeActor: Phantom mirage foe dissolved into black smoke on hit!"));
	Destroy();
}
