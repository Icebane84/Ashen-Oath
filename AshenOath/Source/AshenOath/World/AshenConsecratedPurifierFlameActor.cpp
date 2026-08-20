// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenConsecratedPurifierFlameActor.h"

AAshenConsecratedPurifierFlameActor::AAshenConsecratedPurifierFlameActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenConsecratedPurifierFlameActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenConsecratedPurifierFlameActor: Consecrated purifier ground flame active for %.1fs."), BurnDuration);
}

void AAshenConsecratedPurifierFlameActor::ExtinguishFlameHazard()
{
	UE_LOG(LogTemp, Log, TEXT("AAshenConsecratedPurifierFlameActor: Ground flame extinguished."));
	Destroy();
}
