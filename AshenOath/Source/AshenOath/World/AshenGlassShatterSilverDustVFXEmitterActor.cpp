// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 827: Ashen Glass Shatter Silver Dust VFX Emitter Actor

#include "AshenGlassShatterSilverDustVFXEmitterActor.h"

AAshenGlassShatterSilverDustVFXEmitterActor::AAshenGlassShatterSilverDustVFXEmitterActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsShatterActive = false;
}

void AAshenGlassShatterSilverDustVFXEmitterActor::TriggerSilverDustShatterVFX(float BurstScale)
{
	bIsShatterActive = true;
	const float Particles = 500.0f * BurstScale;

	OnSilverDustShatterTriggered.Broadcast(GetActorLocation(), Particles);

	UE_LOG(LogTemp, Warning, TEXT("AAshenGlassShatterSilverDustVFXEmitterActor: GLASS SHATTER SILVER DUST VFX TRIGGERED -> Location: (%s) | Particle Count: %.0f."),
		*GetActorLocation().ToString(), Particles);
}
