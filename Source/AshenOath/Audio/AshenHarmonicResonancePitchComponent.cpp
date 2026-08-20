// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenHarmonicResonancePitchComponent.h"

UAshenHarmonicResonancePitchComponent::UAshenHarmonicResonancePitchComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	FilamentPitchFrequencyHz = 440.0f;
}
void UAshenHarmonicResonancePitchComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenHarmonicResonancePitchComponent::UpdateFilamentPitch(float TrustScalar, float DebtScalar)
{
	const float Tr = FMath::Clamp(TrustScalar, 0.0f, 1.0f);
	FilamentPitchFrequencyHz = 220.0f + (Tr * 660.0f); // 220Hz to 880Hz
	UE_LOG(LogTemp, Log, TEXT("UAshenHarmonicResonancePitchComponent: Filament Pitch Modulation: %.1fHz (Trust: %.2f)"),
		FilamentPitchFrequencyHz, Tr);
}
