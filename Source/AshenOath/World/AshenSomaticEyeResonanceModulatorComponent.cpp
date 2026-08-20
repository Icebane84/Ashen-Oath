// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenSomaticEyeResonanceModulatorComponent.h"

UAshenSomaticEyeResonanceModulatorComponent::UAshenSomaticEyeResonanceModulatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSomaticEyeResonanceModulatorComponent::UpdateEyeEmissive(float Corruption)
{
	EyeEmissiveIntensity = FMath::Clamp(Corruption * 5.0f, 0.0f, 5.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticEyeResonanceModulatorComponent: Eye emissive intensity updated to %.2f"), EyeEmissiveIntensity);
}
