// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenMindscapeSpectralDioramaComponent.h"

UAshenMindscapeSpectralDioramaComponent::UAshenMindscapeSpectralDioramaComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentScrubTime = 0.0f;
	bReenactmentActive = false;
}

void UAshenMindscapeSpectralDioramaComponent::ScrubTimeline(
	float NormalizedTime)
{
	CurrentScrubTime = FMath::Clamp(NormalizedTime, 0.0f, 1.0f);
	bReenactmentActive = (CurrentScrubTime > 0.0f);
}
