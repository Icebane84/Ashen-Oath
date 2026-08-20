// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenSpectralLanternPostProcessAdapter.h"

UAshenSpectralLanternPostProcessAdapter::UAshenSpectralLanternPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenSpectralLanternPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenSpectralLanternPostProcessAdapter::ApplySpectralLanternPostProcess(bool bIsLit, float Intensity)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSpectralLanternPostProcessAdapter: Spectral lighting postprocess updated — Lit: %s | Intensity: %.2f"),
		bIsLit ? TEXT("TRUE") : TEXT("FALSE"), Intensity);
}
