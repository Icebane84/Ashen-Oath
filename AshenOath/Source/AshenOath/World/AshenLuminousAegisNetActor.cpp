// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenLuminousAegisNetActor.h"

AAshenLuminousAegisNetActor::AAshenLuminousAegisNetActor()
{
	PrimaryActorTick.bCanEverTick = false;
	LatticeGlowIntensity = 1.0f;
}
void AAshenLuminousAegisNetActor::BeginPlay() { Super::BeginPlay(); }

void AAshenLuminousAegisNetActor::SetLatticeTensionVisual(float TensionScalar)
{
	LatticeGlowIntensity = 1.0f + (FMath::Clamp(TensionScalar, 0.0f, 1.0f) * 3.0f); // 1.0 to 4.0 Glow
	UE_LOG(LogTemp, Log, TEXT("AAshenLuminousAegisNetActor: Lattice Glow Intensity: %.2f"), LatticeGlowIntensity);
}
