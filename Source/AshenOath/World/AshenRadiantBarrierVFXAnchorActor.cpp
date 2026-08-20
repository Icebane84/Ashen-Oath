// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 727: Ashen Radiant Barrier VFX Anchor Actor

#include "AshenRadiantBarrierVFXAnchorActor.h"

AAshenRadiantBarrierVFXAnchorActor::AAshenRadiantBarrierVFXAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsLuminanceActive = false;
}

void AAshenRadiantBarrierVFXAnchorActor::TriggerRadiantBarrierVFX(float Luminance)
{
	bIsLuminanceActive = true;
	OnBarrierVFXTriggered.Broadcast(GetActorLocation(), Luminance);

	UE_LOG(LogTemp, Warning, TEXT("AAshenRadiantBarrierVFXAnchorActor: RADIANT BARRIER VFX TRIGGERED -> Center: (%s) | Luminance: %.2f."),
		*GetActorLocation().ToString(), Luminance);
}
