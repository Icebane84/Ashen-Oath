// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 747: Ashen Memory Palace Constellation VFX Anchor Actor

#include "AshenMemoryPalaceConstellationVFXAnchorActor.h"

AAshenMemoryPalaceConstellationVFXAnchorActor::AAshenMemoryPalaceConstellationVFXAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsConstellationRendered = false;
}

void AAshenMemoryPalaceConstellationVFXAnchorActor::RenderConstellationLine(FVector Origin, FVector Target)
{
	bIsConstellationRendered = true;
	OnConstellationVFXRendered.Broadcast(Origin, Target);

	UE_LOG(LogTemp, Warning, TEXT("AAshenMemoryPalaceConstellationVFXAnchorActor: CONSTELLATION LINE RENDERED -> Origin: (%s) -> Target: (%s)."),
		*Origin.ToString(), *Target.ToString());
}
