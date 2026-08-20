// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 587: Ashen Atmospheric Sanity Modifier Volume

#include "AshenAtmosphericSanityModifierVolume.h"

AAshenAtmosphericSanityModifierVolume::AAshenAtmosphericSanityModifierVolume()
{
	PrimaryActorTick.bCanEverTick = false;
	CurrentDrainMultiplier = 1.0f;
	bIsSanctuarySafeZone = false;
}

void AAshenAtmosphericSanityModifierVolume::EvaluateSanityDrainModifier(float CorruptionLevelPercent)
{
	if (bIsSanctuarySafeZone)
	{
		CurrentDrainMultiplier = 0.0f; // No drain in sanctuary
	}
	else
	{
		CurrentDrainMultiplier = FMath::Clamp(1.0f + (CorruptionLevelPercent / 50.0f), 1.0f, 3.0f);
	}

	OnSanityModifierEvaluated.Broadcast(CurrentDrainMultiplier, bIsSanctuarySafeZone);

	UE_LOG(LogTemp, Warning, TEXT("AAshenAtmosphericSanityModifierVolume: SANITY DRAIN EVALUATED -> Multiplier: %.2fx (SafeZone: %s)."),
		CurrentDrainMultiplier, bIsSanctuarySafeZone ? TEXT("TRUE") : TEXT("FALSE"));
}
