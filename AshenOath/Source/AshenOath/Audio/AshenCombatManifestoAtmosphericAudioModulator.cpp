// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 814: Ashen Combat Manifesto Atmospheric Audio Modulator

#include "AshenCombatManifestoAtmosphericAudioModulator.h"

void UAshenCombatManifestoAtmosphericAudioModulator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalAudioModulationsApplied = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenCombatManifestoAtmosphericAudioModulator: Initialized — Combat Manifesto Audio Modulator ONLINE."));
}

void UAshenCombatManifestoAtmosphericAudioModulator::ModulateManifestoAudio(FName GrammarStateTag)
{
	TotalAudioModulationsApplied++;
	float BellVol = 0.0f;
	float ThrumVol = 0.0f;

	if (GrammarStateTag.IsEqual(FName(TEXT("Grammar.WhiteFlame"))))
	{
		BellVol = 1.0f;
		ThrumVol = 0.1f;
	}
	else if (GrammarStateTag.IsEqual(FName(TEXT("Grammar.Shadow"))))
	{
		BellVol = 0.0f;
		ThrumVol = 1.0f;
	}
	else
	{
		BellVol = 0.8f;
		ThrumVol = 0.8f;
	}

	OnManifestoAudioModulated.Broadcast(BellVol, ThrumVol);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCombatManifestoAtmosphericAudioModulator: MANIFESTO AUDIO MODULATED -> State: '%s' | Silver Bell Vol: %.2f | Thrum Vol: %.2f (Total: %d)."),
		*GrammarStateTag.ToString(), BellVol, ThrumVol, TotalAudioModulationsApplied);
}
