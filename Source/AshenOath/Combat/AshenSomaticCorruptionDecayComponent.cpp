// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenSomaticCorruptionDecayComponent.h"

UAshenSomaticCorruptionDecayComponent::UAshenSomaticCorruptionDecayComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSomaticCorruptionDecayComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSomaticCorruptionDecayComponent::AccumulateSomaticCorruption(float Amount)
{
	AccumulatedCorruptionLevel = FMath::Clamp(AccumulatedCorruptionLevel + Amount, 0.0f, 100.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticCorruptionDecayComponent: Accumulated corruption level is now %f"), AccumulatedCorruptionLevel);
}

float UAshenSomaticCorruptionDecayComponent::GetEffectivePoiseDecayMultiplier() const
{
	return 1.0f + (AccumulatedCorruptionLevel / 100.0f) * (StaminaDecayMultiplier - 1.0f);
}
