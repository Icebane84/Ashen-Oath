// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenMemoryPalaceLocusActor.h"

AAshenMemoryPalaceLocusActor::AAshenMemoryPalaceLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
	InteractionRadius = 400.0f;
}
void AAshenMemoryPalaceLocusActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenMemoryPalaceLocusActor::InteractWithLocus(AActor* InteractingPlayer)
{
	if (!InteractingPlayer) return false;
	LocusNodeData.bIsUnsealed = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenMemoryPalaceLocusActor: Player successfully unsealed Memory Locus '%s'!"),
		*LocusNodeData.NodeID.ToString());
	return true;
}
