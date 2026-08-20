// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 712: Ashen Smoke Screen VFX Emitter Actor

#include "AshenSmokeScreenVFXEmitterActor.h"

AAshenSmokeScreenVFXEmitterActor::AAshenSmokeScreenVFXEmitterActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsEmitting = false;
}

void AAshenSmokeScreenVFXEmitterActor::TriggerSmokeScreenVFX(float Density)
{
	bIsEmitting = true;
	OnSmokeVFXTriggered.Broadcast(GetActorLocation(), Density);

	UE_LOG(LogTemp, Warning, TEXT("AAshenSmokeScreenVFXEmitterActor: SMOKE SCREEN VFX EMITTER TRIGGERED -> Location: (%s) | Density: %.2f."),
		*GetActorLocation().ToString(), Density);
}
