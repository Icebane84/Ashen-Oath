// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenMemoryPalaceSanctuaryAltarActor.h"

AAshenMemoryPalaceSanctuaryAltarActor::AAshenMemoryPalaceSanctuaryAltarActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsSanctuaryActive = false;
}
void AAshenMemoryPalaceSanctuaryAltarActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenMemoryPalaceSanctuaryAltarActor::ConsecrateSanctuaryAltar(AActor* InteractingPlayer)
{
	if (!InteractingPlayer) return false;
	bIsSanctuaryActive = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenMemoryPalaceSanctuaryAltarActor: Mindscape Sanctuary Altar successfully consecrated!"));
	return true;
}
