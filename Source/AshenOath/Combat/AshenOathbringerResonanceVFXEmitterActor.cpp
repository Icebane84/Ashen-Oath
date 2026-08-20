// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenOathbringerResonanceVFXEmitterActor.h"

AAshenOathbringerResonanceVFXEmitterActor::AAshenOathbringerResonanceVFXEmitterActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenOathbringerResonanceVFXEmitterActor::TriggerSwordResonanceVFX(float Intensity)
{
	UE_LOG(LogTemp, Warning, TEXT("AAshenOathbringerResonanceVFXEmitterActor: Triggered Oathbringer sword resonance VFX (Intensity: %.2f)"), Intensity);
}
