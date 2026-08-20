// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenCartographerMemoryConstellationActor.h"

AAshenCartographerMemoryConstellationActor::AAshenCartographerMemoryConstellationActor()
{
	PrimaryActorTick.bCanEverTick = false;
	CurrentNodeVisual = EConstellationNodeVisual::Unresolved;
}
void AAshenCartographerMemoryConstellationActor::BeginPlay() { Super::BeginPlay(); }

void AAshenCartographerMemoryConstellationActor::InscribeSectorResolution(EJournalPerspectiveType Perspective)
{
	if (Perspective == EJournalPerspectiveType::TripartiteSynarchy)
	{
		CurrentNodeVisual = EConstellationNodeVisual::GoldWhiteLeyConduit;
		UE_LOG(LogTemp, Warning, TEXT("AAshenCartographerMemoryConstellationActor: Sector inscribed as GOLD-WHITE LEY CONDUIT."));
	}
	else
	{
		CurrentNodeVisual = EConstellationNodeVisual::ObsidianFracture;
		UE_LOG(LogTemp, Warning, TEXT("AAshenCartographerMemoryConstellationActor: Sector inscribed as OBSIDIAN FRACTURE."));
	}
}
