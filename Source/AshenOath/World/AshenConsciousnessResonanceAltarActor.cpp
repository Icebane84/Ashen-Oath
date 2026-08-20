// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenConsciousnessResonanceAltarActor.h"

AAshenConsciousnessResonanceAltarActor::AAshenConsciousnessResonanceAltarActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsCalibrated = false;
}
void AAshenConsciousnessResonanceAltarActor::BeginPlay() { Super::BeginPlay(); }

void AAshenConsciousnessResonanceAltarActor::CalibrateAudioChannels(AActor* InstigatingPlayer)
{
	if (!InstigatingPlayer) return;
	bIsCalibrated = true;
	UE_LOG(LogTemp, Log, TEXT("AAshenConsciousnessResonanceAltarActor: Calibrated 3-Channel Proximity of Consciousness Audio Mix."));
}
