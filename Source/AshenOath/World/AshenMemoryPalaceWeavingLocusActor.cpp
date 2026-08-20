// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 739: Ashen Memory Palace Weaving Locus Actor

#include "AshenMemoryPalaceWeavingLocusActor.h"

AAshenMemoryPalaceWeavingLocusActor::AAshenMemoryPalaceWeavingLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsWeaved = false;
}

void AAshenMemoryPalaceWeavingLocusActor::ExecuteMemoryWeavingPass(bool bSelectGraceLens)
{
	bIsWeaved = true;
	OnWeavingLocusActivated.Broadcast(BoundMemoryNodeTag, bSelectGraceLens);

	UE_LOG(LogTemp, Warning, TEXT("AAshenMemoryPalaceWeavingLocusActor: MEMORY WEAVING PASS EXECUTED -> Bound Node: '%s' | Lens Selected: %s."),
		*BoundMemoryNodeTag.ToString(), bSelectGraceLens ? TEXT("GRACE LENS") : TEXT("ACCOUNTABILITY LENS"));
}
