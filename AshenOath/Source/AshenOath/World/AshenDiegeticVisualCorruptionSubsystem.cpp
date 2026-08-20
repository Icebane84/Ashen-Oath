// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 493: Ashen Diegetic Visual Corruption Subsystem

#include "AshenDiegeticVisualCorruptionSubsystem.h"

void UAshenDiegeticVisualCorruptionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticVisualCorruptionSubsystem: Initialized — Diegetic Visual Corruption Subsystem ONLINE."));
}

void UAshenDiegeticVisualCorruptionSubsystem::ModulateVisualCorruptionForTrauma(float TraumaLevel)
{
	const float Normalized = FMath::Clamp(TraumaLevel / 100.0f, 0.0f, 1.0f);
	const float ChromaticAberration = Normalized * 5.0f;
	const float LensDistortion = Normalized * 0.35f;

	OnVisualCorruptionUpdated.Broadcast(ChromaticAberration, LensDistortion);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticVisualCorruptionSubsystem: VISUAL CORRUPTION MODULATED -> Trauma %.1f (Aberration: %.2f | Lens Distortion: %.2f)."),
		TraumaLevel, ChromaticAberration, LensDistortion);
}
