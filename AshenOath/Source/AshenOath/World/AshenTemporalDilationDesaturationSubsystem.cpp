// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 821: Ashen Temporal Dilation Desaturation Subsystem

#include "AshenTemporalDilationDesaturationSubsystem.h"

void UAshenTemporalDilationDesaturationSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveTimeDilation = 1.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenTemporalDilationDesaturationSubsystem: Initialized — Temporal Dilation & Desaturation Subsystem ONLINE."));
}

void UAshenTemporalDilationDesaturationSubsystem::ApplyTemporalDilation(float DilationScale)
{
	ActiveTimeDilation = DilationScale;
	const float Desat = (ActiveTimeDilation <= 0.20f) ? 0.90f : 0.0f; // 90% desaturation during 10% dilation

	OnTemporalDilationApplied.Broadcast(ActiveTimeDilation, Desat);

	UE_LOG(LogTemp, Warning, TEXT("UAshenTemporalDilationDesaturationSubsystem: TEMPORAL DILATION APPLIED -> Speed: %.2fx | World Slate Desaturation: %.0f%%."),
		ActiveTimeDilation, Desat * 100.0f);
}
