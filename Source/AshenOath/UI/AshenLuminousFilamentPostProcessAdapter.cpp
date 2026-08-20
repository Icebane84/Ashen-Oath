// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenLuminousFilamentPostProcessAdapter.h"

UAshenLuminousFilamentPostProcessAdapter::UAshenLuminousFilamentPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	FilamentBloomIntensity = 0.0f;
}
void UAshenLuminousFilamentPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenLuminousFilamentPostProcessAdapter::ApplyFilamentBloom(float TensionScalar)
{
	FilamentBloomIntensity = FMath::Clamp(TensionScalar, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenLuminousFilamentPostProcessAdapter: Filament Anamorphic Bloom: %.2f"), FilamentBloomIntensity);
}
