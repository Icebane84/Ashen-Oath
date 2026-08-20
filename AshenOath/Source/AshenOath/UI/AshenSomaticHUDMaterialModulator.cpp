// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenSomaticHUDMaterialModulator.h"

UAshenSomaticHUDMaterialModulator::UAshenSomaticHUDMaterialModulator()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenSomaticHUDMaterialModulator::BeginPlay() { Super::BeginPlay(); }

void UAshenSomaticHUDMaterialModulator::ModulateHUDMaterialParameters(float StaminaPercent, float SanityPercent)
{
	HeartbeatPulseRate = FMath::Lerp(3.0f, 1.0f, FMath::Clamp(StaminaPercent, 0.0f, 1.0f));
	ChromaticAberrationIntensity = (1.0f - FMath::Clamp(SanityPercent, 0.0f, 1.0f)) * 0.8f;
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticHUDMaterialModulator: Pulse Rate: %.2f | Chromatic Aberration: %.2f"),
		HeartbeatPulseRate, ChromaticAberrationIntensity);
}
