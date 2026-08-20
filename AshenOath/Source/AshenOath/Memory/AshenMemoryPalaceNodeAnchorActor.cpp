// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 631: Ashen Memory Palace Node Anchor Actor

#include "AshenMemoryPalaceNodeAnchorActor.h"

AAshenMemoryPalaceNodeAnchorActor::AAshenMemoryPalaceNodeAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsAnchored = false;
	AnchoredMemoryID = FName(TEXT("Memory.NodeDefault"));
}

void AAshenMemoryPalaceNodeAnchorActor::AnchorMemoryNode(FName MemoryID, float ResonancePower)
{
	AnchoredMemoryID = MemoryID;
	bIsAnchored = true;
	OnMemoryNodeAnchored.Broadcast(AnchoredMemoryID, ResonancePower);

	UE_LOG(LogTemp, Warning, TEXT("AAshenMemoryPalaceNodeAnchorActor: MEMORY NODE ANCHORED -> Memory '%s' | Resonance: %.0f."),
		*AnchoredMemoryID.ToString(), ResonancePower);
}
