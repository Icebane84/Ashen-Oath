// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenOathbringerSomaticVFXComponent.h"

UAshenOathbringerSomaticVFXComponent::UAshenOathbringerSomaticVFXComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	NightsteelStainCoverage = 0.0f;
	WolfHeadGarnetGlow = 0.2f;
}
void UAshenOathbringerSomaticVFXComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenOathbringerSomaticVFXComponent::UpdateOathbringerSomaticState(float CorruptionScalar, bool bIsDarkMode)
{
	const float C = FMath::Clamp(CorruptionScalar, 0.0f, 1.0f);
	NightsteelStainCoverage = C;

	if (bIsDarkMode)
	{
		// Piercing violet/crimson void fire
		WolfHeadGarnetGlow = 1.5f + (C * 1.5f); // 1.5 to 3.0
	}
	else
	{
		// Gentle ambient amber flame
		WolfHeadGarnetGlow = 0.2f + (C * 0.6f); // 0.2 to 0.8
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenOathbringerSomaticVFXComponent: Oathbringer Somatic State -> Stain: %.2f | Garnet Eye Glow: %.2f (Dark: %s)"),
		NightsteelStainCoverage, WolfHeadGarnetGlow, bIsDarkMode ? TEXT("TRUE") : TEXT("FALSE"));
}
