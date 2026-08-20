// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenFlameBladeTrailParticleModulatorActor.h"

AAshenFlameBladeTrailParticleModulatorActor::AAshenFlameBladeTrailParticleModulatorActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenFlameBladeTrailParticleModulatorActor::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	RibbonTrailLengthScalar = 1.0f + (NewState.Corruption * 3.0f);
	UE_LOG(LogTemp, Log, TEXT("AAshenFlameBladeTrailParticleModulatorActor: Ribbon trail length scalar set to %.2f"), RibbonTrailLengthScalar);
}
