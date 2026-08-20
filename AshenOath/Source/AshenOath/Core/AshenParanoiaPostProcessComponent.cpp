// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 242: Ashen Paranoia Post Process Component

#include "AshenParanoiaPostProcessComponent.h"

UAshenParanoiaPostProcessComponent::UAshenParanoiaPostProcessComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentVignette = 0.0f;
	CurrentChromaticAberration = 0.0f;
}

void UAshenParanoiaPostProcessComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenParanoiaPostProcessComponent::UpdateParanoiaVFX(float ParanoiaLevel)
{
	const float NormalizedParanoia = FMath::Clamp(ParanoiaLevel / 100.0f, 0.0f, 1.0f);

	// Vignette contracts from 0.0 to 0.85 as paranoia reaches 100%
	CurrentVignette = NormalizedParanoia * 0.85f;

	// Chromatic aberration jitters up to 3.5x as paranoia reaches 100%
	CurrentChromaticAberration = NormalizedParanoia * 3.5f;

	OnParanoiaVFXUpdated.Broadcast(CurrentVignette, CurrentChromaticAberration);

	UE_LOG(LogTemp, Log, TEXT("UAshenParanoiaPostProcessComponent: Paranoia %.1f%% — Vignette: %.2f, Chromatic Aberration: %.2f."),
		ParanoiaLevel, CurrentVignette, CurrentChromaticAberration);
}
