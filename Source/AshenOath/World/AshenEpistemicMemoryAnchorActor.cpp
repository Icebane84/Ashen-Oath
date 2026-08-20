// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenEpistemicMemoryAnchorActor.h"

AAshenEpistemicMemoryAnchorActor::AAshenEpistemicMemoryAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;
	AnchoredEncounterID = NAME_None;
	bIsAnchorActive = false;
}
void AAshenEpistemicMemoryAnchorActor::BeginPlay() { Super::BeginPlay(); }

void AAshenEpistemicMemoryAnchorActor::EstablishAnchor(FName EncounterID, bool bIsSynarchy)
{
	AnchoredEncounterID = EncounterID;
	bIsAnchorActive = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenEpistemicMemoryAnchorActor: Established Memory Anchor for %s (Synarchy: %s)."),
		*EncounterID.ToString(), bIsSynarchy ? TEXT("TRUE") : TEXT("FALSE"));
}
