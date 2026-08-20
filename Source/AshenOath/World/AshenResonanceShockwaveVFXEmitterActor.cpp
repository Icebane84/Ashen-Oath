// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 791: Ashen Resonance Shockwave VFX Emitter Actor

#include "AshenResonanceShockwaveVFXEmitterActor.h"

AAshenResonanceShockwaveVFXEmitterActor::AAshenResonanceShockwaveVFXEmitterActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsWaveActive = false;
}

void AAshenResonanceShockwaveVFXEmitterActor::TriggerResonanceShockwaveVFX(float Scale)
{
	bIsWaveActive = true;
	OnResonanceShockwaveTriggered.Broadcast(GetActorLocation(), Scale);

	UE_LOG(LogTemp, Warning, TEXT("AAshenResonanceShockwaveVFXEmitterActor: RESONANCE SHOCKWAVE VFX TRIGGERED -> Location: (%s) | Scale: %.2fx."),
		*GetActorLocation().ToString(), Scale);
}
