// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 246: Ashen Sanity Corrupted VFX Component

#include "AshenSanityCorruptedVFXComponent.h"

UAshenSanityCorruptedVFXComponent::UAshenSanityCorruptedVFXComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	LowSanityThreshold = 40.0f;
	bLowSanityVFXActive = false;
	CurrentSmokeDensity = 0.0f;
}

void UAshenSanityCorruptedVFXComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSanityCorruptedVFXComponent::UpdateSanityVFX(float CurrentSanity, float MaxSanity)
{
	if (MaxSanity <= 0.0f) return;

	const float SanityPct = (CurrentSanity / MaxSanity) * 100.0f;
	bLowSanityVFXActive = (SanityPct <= LowSanityThreshold);

	if (bLowSanityVFXActive)
	{
		CurrentSmokeDensity = (1.0f - (SanityPct / LowSanityThreshold));
	}
	else
	{
		CurrentSmokeDensity = 0.0f;
	}

	OnSanityVFXTriggered.Broadcast(bLowSanityVFXActive, CurrentSmokeDensity);

	UE_LOG(LogTemp, Log, TEXT("UAshenSanityCorruptedVFXComponent: Sanity %.1f%% — Low Sanity VFX: %s (Smoke Density: %.2f)."),
		SanityPct, bLowSanityVFXActive ? TEXT("ACTIVE") : TEXT("INACTIVE"), CurrentSmokeDensity);
}
