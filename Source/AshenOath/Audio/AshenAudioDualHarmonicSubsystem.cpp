// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 309: Ashen Audio Dual Harmonic Subsystem (UMB-SYS-005)

#include "AshenAudioDualHarmonicSubsystem.h"

void UAshenAudioDualHarmonicSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	bHarmonicActive = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenAudioDualHarmonicSubsystem: Initialized — Dual-Harmonic Audio Subsystem (UMB-SYS-005) ONLINE."));
}

void UAshenAudioDualHarmonicSubsystem::ShiftToDualHarmonicAuthority(bool bEnableHarmonic, float BlendWeight)
{
	bHarmonicActive = bEnableHarmonic;
	OnDualHarmonicAudioShift.Broadcast(bEnableHarmonic, BlendWeight);

	if (bEnableHarmonic)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenAudioDualHarmonicSubsystem: DUAL-HARMONIC VOICE AUTHORITY ACTIVE — Ragged Breathing Stripped, Weight: %.2f."), BlendWeight);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("UAshenAudioDualHarmonicSubsystem: Dual-harmonic voice authority deactivated. Normal breathing restored."));
	}
}
