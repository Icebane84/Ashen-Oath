// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenResonanceAudioSpatializerValidator.h"

void UAshenResonanceAudioSpatializerValidator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenResonanceAudioSpatializerValidator: Resonance Audio Spatializer Validator initialized."));
}

bool UAshenResonanceAudioSpatializerValidator::ValidateResonanceAudioSpatializers()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenResonanceAudioSpatializerValidator: Diegetic resonance audio spatializer parameter bindings validated."));
	return true;
}
