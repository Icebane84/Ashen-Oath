// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 731: Ashen Radiant Beam VFX Emitter Actor

#include "AshenRadiantBeamVFXEmitterActor.h"

AAshenRadiantBeamVFXEmitterActor::AAshenRadiantBeamVFXEmitterActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsBeamActive = false;
}

void AAshenRadiantBeamVFXEmitterActor::TriggerRadiantBeamVFX(FVector TargetLocation, float Width)
{
	bIsBeamActive = true;
	OnRadiantBeamTriggered.Broadcast(TargetLocation, Width);

	UE_LOG(LogTemp, Warning, TEXT("AAshenRadiantBeamVFXEmitterActor: RADIANT BEAM VFX TRIGGERED -> Target: (%s) | Beam Width: %.0f units."),
		*TargetLocation.ToString(), Width);
}
