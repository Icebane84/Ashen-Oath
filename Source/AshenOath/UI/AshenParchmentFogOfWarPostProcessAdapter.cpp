// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenParchmentFogOfWarPostProcessAdapter.h"

UAshenParchmentFogOfWarPostProcessAdapter::UAshenParchmentFogOfWarPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	InkWashOpacity = 1.0f;
}
void UAshenParchmentFogOfWarPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenParchmentFogOfWarPostProcessAdapter::SetInkWashDensity(float InDensity)
{
	InkWashOpacity = FMath::Clamp(InDensity, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenParchmentFogOfWarPostProcessAdapter: Ink Wash Fog Opacity: %.2f"), InkWashOpacity);
}
