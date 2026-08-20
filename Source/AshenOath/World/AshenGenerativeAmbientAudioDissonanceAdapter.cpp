// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenGenerativeAmbientAudioDissonanceAdapter.h"

UAshenGenerativeAmbientAudioDissonanceAdapter::UAshenGenerativeAmbientAudioDissonanceAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGenerativeAmbientAudioDissonanceAdapter::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	AmbientAudioPitchMultiplier = FMath::Clamp(1.0f - (NewState.IntegrationDebt * 0.25f), 0.75f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenGenerativeAmbientAudioDissonanceAdapter: Ambient audio pitch multiplier set to %.2f"), AmbientAudioPitchMultiplier);
}
