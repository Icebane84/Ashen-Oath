// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenAudioWhisperPhenotypeModulator.h"

UAshenAudioWhisperPhenotypeModulator::UAshenAudioWhisperPhenotypeModulator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenAudioWhisperPhenotypeModulator::UpdateWhisperDensity(float IntegrationDebt, float Corruption)
{
	WhisperVolumeMultiplier = FMath::Clamp((IntegrationDebt * 0.6f) + (Corruption * 0.4f), 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenAudioWhisperPhenotypeModulator: Whisper volume multiplier updated to %.2f"), WhisperVolumeMultiplier);
}
