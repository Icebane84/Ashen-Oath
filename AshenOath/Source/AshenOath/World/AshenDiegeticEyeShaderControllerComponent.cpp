// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 496: Ashen Diegetic Eye Shader Controller Component

#include "AshenDiegeticEyeShaderControllerComponent.h"

UAshenDiegeticEyeShaderControllerComponent::UAshenDiegeticEyeShaderControllerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CalculatedEmissiveIntensity = 1.0f;
	CalculatedEyeGlowColor = FLinearColor::Blue;
}

void UAshenDiegeticEyeShaderControllerComponent::UpdateEyeGlowState(float SanityLevel, float CorruptionLevel)
{
	const float NormalizedCorruption = FMath::Clamp(CorruptionLevel / 100.0f, 0.0f, 1.0f);
	CalculatedEmissiveIntensity = 1.0f + (NormalizedCorruption * 9.0f); // 1.0 -> 10.0 Emissive
	CalculatedEyeGlowColor = FLinearColor::LerpUsingHSV(FLinearColor::Blue, FLinearColor::Red, NormalizedCorruption);

	OnEyeGlowUpdated.Broadcast(CalculatedEmissiveIntensity, CalculatedEyeGlowColor);

	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticEyeShaderControllerComponent: EYE SHADER GLOW UPDATED — Intensity: %.1f | Color (%s)."),
		CalculatedEmissiveIntensity, *CalculatedEyeGlowColor.ToString());
}
