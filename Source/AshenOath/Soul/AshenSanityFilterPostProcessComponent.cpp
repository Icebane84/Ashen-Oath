// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 184: Ashen Sanity Filter Post-Process Component

#include "AshenSanityFilterPostProcessComponent.h"

UAshenSanityFilterPostProcessComponent::UAshenSanityFilterPostProcessComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	MaxVignetteIntensity = 0.8f;
	MaxChromaticAberration = 4.0f;
	DistortionIntensity = 0.0f;
}

void UAshenSanityFilterPostProcessComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSanityFilterPostProcessComponent::UpdateFilterFromSanity(float CurrentSanity, float MaxSanity)
{
	if (MaxSanity <= 0.0f) return;

	const float SanityRatio = FMath::Clamp(CurrentSanity / MaxSanity, 0.0f, 1.0f);
	DistortionIntensity = 1.0f - SanityRatio; // Low sanity = high distortion

	const float CurrentVignette = DistortionIntensity * MaxVignetteIntensity;
	const float CurrentChromatic = DistortionIntensity * MaxChromaticAberration;

	OnSanityFilterUpdated.Broadcast(DistortionIntensity);

	UE_LOG(LogTemp, Log, TEXT("UAshenSanityFilterPostProcessComponent: Sanity %.0f/%.0f (Distortion %.1f%%) — Vignette: %.2f, Chromatic: %.2f."),
		CurrentSanity, MaxSanity, DistortionIntensity * 100.0f, CurrentVignette, CurrentChromatic);
}
