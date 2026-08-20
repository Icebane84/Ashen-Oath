// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 734: Ashen Serafina Holy Atmospheric Audio Modulator

#include "AshenSerafinaHolyAtmosphericAudioModulator.h"

void UAshenSerafinaHolyAtmosphericAudioModulator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalAudioModulationsApplied = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaHolyAtmosphericAudioModulator: Initialized — Serafina Holy Atmospheric Audio Modulator ONLINE."));
}

void UAshenSerafinaHolyAtmosphericAudioModulator::ModulateSerafinaHolyAudio(bool bIsPurgeActive, float EmpathicResonanceLevel)
{
	TotalAudioModulationsApplied++;
	const float ChoralVol = bIsPurgeActive ? 1.0f : 0.4f;
	const float ReverbFilter = FMath::Clamp(EmpathicResonanceLevel / 100.0f, 0.2f, 1.0f);

	OnSerafinaAudioModulated.Broadcast(ChoralVol, ReverbFilter);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaHolyAtmosphericAudioModulator: HOLY AUDIO MODULATED -> Choral Vol: %.2f | Reverb Filter: %.2f (Total: %d)."),
		ChoralVol, ReverbFilter, TotalAudioModulationsApplied);
}
