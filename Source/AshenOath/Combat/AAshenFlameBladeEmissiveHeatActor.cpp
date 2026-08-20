// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AAshenFlameBladeEmissiveHeatActor.h"

AAshenFlameBladeEmissiveHeatActor::AAshenFlameBladeEmissiveHeatActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenFlameBladeEmissiveHeatActor::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	HeatEmissiveIntensity = 1.0f + (NewState.Corruption * 5.0f);
	UE_LOG(LogTemp, Log, TEXT("AAshenFlameBladeEmissiveHeatActor: Heat emissive intensity set to %.2f"), HeatEmissiveIntensity);
}
