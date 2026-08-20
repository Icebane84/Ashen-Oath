// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 756: Ashen Blackwood Bridge Level Manager Actor

#include "AshenBlackwoodBridgeLevelManagerActor.h"

AAshenBlackwoodBridgeLevelManagerActor::AAshenBlackwoodBridgeLevelManagerActor()
{
	PrimaryActorTick.bCanEverTick = false;
	StructuralIntegrityPercent = 100.0f;
}

void AAshenBlackwoodBridgeLevelManagerActor::TriggerBridgeCollapsePhase(FName CollapsePhaseTag)
{
	StructuralIntegrityPercent = FMath::Clamp(StructuralIntegrityPercent - 33.3f, 0.0f, 100.0f);
	OnBridgeCollapseTriggered.Broadcast(CollapsePhaseTag, StructuralIntegrityPercent);

	UE_LOG(LogTemp, Warning, TEXT("AAshenBlackwoodBridgeLevelManagerActor: BRIDGE COLLAPSE PHASE TRIGGERED -> Phase: '%s' | Structural Integrity: %.1f%%."),
		*CollapsePhaseTag.ToString(), StructuralIntegrityPercent);
}
