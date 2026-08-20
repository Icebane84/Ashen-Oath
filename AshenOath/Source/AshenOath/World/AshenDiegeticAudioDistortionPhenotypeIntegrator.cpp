// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenDiegeticAudioDistortionPhenotypeIntegrator.h"

UAshenDiegeticAudioDistortionPhenotypeIntegrator::UAshenDiegeticAudioDistortionPhenotypeIntegrator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticAudioDistortionPhenotypeIntegrator::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	AudioDistortion = FMath::Clamp(NewState.Corruption * 0.75f, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticAudioDistortionPhenotypeIntegrator: Audio distortion updated to %.2f"), AudioDistortion);
}
