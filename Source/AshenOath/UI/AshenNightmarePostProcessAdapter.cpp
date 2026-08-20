// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenNightmarePostProcessAdapter.h"

UAshenNightmarePostProcessAdapter::UAshenNightmarePostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenNightmarePostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenNightmarePostProcessAdapter::ApplyNightmareVisualDistortion(float IncursionIntensity, float StrainLevel)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenNightmarePostProcessAdapter: Applied Nightmare Post-Process -> Intensity: %.2f, Strain: %.2f"),
		IncursionIntensity, StrainLevel);
}
