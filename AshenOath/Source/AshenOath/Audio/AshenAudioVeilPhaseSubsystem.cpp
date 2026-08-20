// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 364: Ashen Audio Veil Phase Subsystem

#include "AshenAudioVeilPhaseSubsystem.h"

void UAshenAudioVeilPhaseSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenAudioVeilPhaseSubsystem: Initialized — Audio Veil Phase Subsystem active."));
}

void UAshenAudioVeilPhaseSubsystem::ShiftAudioVeilState(EAshenWorldVeilState VeilState)
{
	const float Cutoff = (VeilState == EAshenWorldVeilState::PrismaticVoidPhase) ? 800.0f : 20000.0f;
	OnAudioVeilShifted.Broadcast(VeilState, Cutoff);

	UE_LOG(LogTemp, Warning, TEXT("UAshenAudioVeilPhaseSubsystem: AUDIO VEIL SHIFTED -> State %d (Low-Pass Cutoff: %.0f Hz)."),
		(int32)VeilState, Cutoff);
}
