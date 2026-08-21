// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Archive/AshenCodexHapticBridge.h"

UAshenCodexHapticBridge::UAshenCodexHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenCodexHapticBridge::EvaluateInspectionHapticIntensity(
	bool bSecretRevealed,
	float DecodedPercent) const
{
	if (bSecretRevealed)
	{
		return 0.90f; // Strong resonant pulse when secret glyph aligns
	}

	// Soft tactile grain as user rotates the relic
	return FMath::Clamp(DecodedPercent * 0.40f, 0.05f, 0.40f);
}
