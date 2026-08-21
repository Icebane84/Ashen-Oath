// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Tactics/AshenTacticalHapticBridge.h"

UAshenTacticalHapticBridge::UAshenTacticalHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenTacticalHapticBridge::EvaluateSectorTickIntensity(int32 OldSector, int32 NewSector) const
{
	if (OldSector != NewSector)
	{
		return 0.65f; // Crisp mechanical detent click
	}

	return 0.0f;
}
