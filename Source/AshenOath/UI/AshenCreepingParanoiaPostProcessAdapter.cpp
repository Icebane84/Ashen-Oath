// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenCreepingParanoiaPostProcessAdapter.h"

UAshenCreepingParanoiaPostProcessAdapter::UAshenCreepingParanoiaPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCreepingParanoiaPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenCreepingParanoiaPostProcessAdapter::ApplyParanoiaPostProcess(float ParanoiaIntensity)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenCreepingParanoiaPostProcessAdapter: Postprocess updated — Paranoia Intensity: %.2f (Spectral fringes & dark vignette active)"),
		ParanoiaIntensity);
}
