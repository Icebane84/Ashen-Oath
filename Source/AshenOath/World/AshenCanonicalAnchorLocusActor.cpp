// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 652: Ashen Canonical Anchor Locus Actor

#include "AshenCanonicalAnchorLocusActor.h"

AAshenCanonicalAnchorLocusActor::AAshenCanonicalAnchorLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsLocusActive = false;
	CANAnchorID = FName(TEXT("can-faith_vs_doubt"));
}

void AAshenCanonicalAnchorLocusActor::ActivateCANLocus(float ConflictIntensity)
{
	bIsLocusActive = true;
	OnCANLocusActivated.Broadcast(CANAnchorID, ConflictIntensity);

	UE_LOG(LogTemp, Warning, TEXT("AAshenCanonicalAnchorLocusActor: CAN LOCUS ACTIVATED -> CAN '%s' | Intensity: %.2f."),
		*CANAnchorID.ToString(), ConflictIntensity);
}
