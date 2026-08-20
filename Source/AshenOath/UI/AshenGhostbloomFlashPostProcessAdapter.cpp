// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenGhostbloomFlashPostProcessAdapter.h"

UAshenGhostbloomFlashPostProcessAdapter::UAshenGhostbloomFlashPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	FlashBloomIntensity = 0.0f;
}
void UAshenGhostbloomFlashPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenGhostbloomFlashPostProcessAdapter::TriggerFlashBloom(float Intensity)
{
	FlashBloomIntensity = FMath::Clamp(Intensity, 0.0f, 1.0f);
	UE_LOG(LogTemp, Warning, TEXT("UAshenGhostbloomFlashPostProcessAdapter: Ghostbloom High-Intensity Retinal Flash: %.2f"),
		FlashBloomIntensity);
}
