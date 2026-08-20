// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenFlameBladeEmissiveResonanceActor.h"

AAshenFlameBladeEmissiveResonanceActor::AAshenFlameBladeEmissiveResonanceActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenFlameBladeEmissiveResonanceActor::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	FlameEmissiveIntensity = 1.0f + (NewState.Corruption * 4.0f);
	UE_LOG(LogTemp, Log, TEXT("AAshenFlameBladeEmissiveResonanceActor: Flame Blade emissive intensity scaled to %.2f"), FlameEmissiveIntensity);
}
