// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenNightmareRiftActor.h"

AAshenNightmareRiftActor::AAshenNightmareRiftActor()
{
	PrimaryActorTick.bCanEverTick = false;
	RiftPulseRadius = 800.0f;
	bIsRiftSealed = false;
}
void AAshenNightmareRiftActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenNightmareRiftActor::SealRift(AActor* InstigatingPlayer)
{
	if (!InstigatingPlayer) return false;
	bIsRiftSealed = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenNightmareRiftActor: Nightmare Rift successfully sealed by Player!"));
	return true;
}
