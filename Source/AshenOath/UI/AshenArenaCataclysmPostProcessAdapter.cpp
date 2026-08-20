// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenArenaCataclysmPostProcessAdapter.h"

UAshenArenaCataclysmPostProcessAdapter::UAshenArenaCataclysmPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	CataclysmDistortionIntensity = 0.0f;
}
void UAshenArenaCataclysmPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenArenaCataclysmPostProcessAdapter::SetCataclysmFXState(bool bEnableCataclysmFX)
{
	CataclysmDistortionIntensity = bEnableCataclysmFX ? 1.0f : 0.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenArenaCataclysmPostProcessAdapter: Cataclysm PostProcess Distortion: %.2f"), CataclysmDistortionIntensity);
}
