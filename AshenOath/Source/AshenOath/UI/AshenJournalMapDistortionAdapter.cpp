// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenJournalMapDistortionAdapter.h"

UAshenJournalMapDistortionAdapter::UAshenJournalMapDistortionAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenJournalMapDistortionAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenJournalMapDistortionAdapter::UpdateMapDistortionForFriction(bool bGuardedFriction, float DebtLevel)
{
	if (bGuardedFriction)
	{
		MapChromaticAberrationIntensity = 1.5f;
		MapMudVignetteIntensity = FMath::Clamp(DebtLevel * 0.8f, 0.4f, 1.0f);
	}
	else
	{
		MapChromaticAberrationIntensity = 0.0f;
		MapMudVignetteIntensity = 0.0f;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenJournalMapDistortionAdapter: Map Distortion — Chromatic Aberration: %.2f | Mud Vignette: %.2f"),
		MapChromaticAberrationIntensity, MapMudVignetteIntensity);
}
