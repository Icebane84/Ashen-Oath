// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 771: Ashen Void Rift VFX Emitter Actor

#include "AshenVoidRiftVFXEmitterActor.h"

AAshenVoidRiftVFXEmitterActor::AAshenVoidRiftVFXEmitterActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsRiftOpen = false;
}

void AAshenVoidRiftVFXEmitterActor::TriggerVoidRiftVFX(float Scale)
{
	bIsRiftOpen = true;
	OnVoidRiftTriggered.Broadcast(GetActorLocation(), Scale);

	UE_LOG(LogTemp, Warning, TEXT("AAshenVoidRiftVFXEmitterActor: VOID RIFT VFX TRIGGERED -> Location: (%s) | Rift Scale: %.2fx."),
		*GetActorLocation().ToString(), Scale);
}
