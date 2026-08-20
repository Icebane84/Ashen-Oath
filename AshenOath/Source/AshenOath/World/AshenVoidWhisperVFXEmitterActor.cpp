// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 751: Ashen Void Whisper VFX Emitter Actor

#include "AshenVoidWhisperVFXEmitterActor.h"

AAshenVoidWhisperVFXEmitterActor::AAshenVoidWhisperVFXEmitterActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsDistorting = false;
}

void AAshenVoidWhisperVFXEmitterActor::TriggerVoidWhisperVFX(float Distortion)
{
	bIsDistorting = true;
	OnVoidWhisperVFXTriggered.Broadcast(GetActorLocation(), Distortion);

	UE_LOG(LogTemp, Warning, TEXT("AAshenVoidWhisperVFXEmitterActor: VOID WHISPER VFX TRIGGERED -> Location: (%s) | Distortion: %.2f."),
		*GetActorLocation().ToString(), Distortion);
}
