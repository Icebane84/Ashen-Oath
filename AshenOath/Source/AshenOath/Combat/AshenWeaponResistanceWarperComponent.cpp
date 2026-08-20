// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenWeaponResistanceWarperComponent.h"

UAshenWeaponResistanceWarperComponent::UAshenWeaponResistanceWarperComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenWeaponResistanceWarperComponent::CalculatePlayRateForVolume(float SubmergedVolumeCM3) const
{
	if (SubmergedVolumeCM3 <= 0.0f)
	{
		return 1.0f;
	}

	// Dynamic drag curve: 10,000 cm3 volume drags play rate down to 0.08 floor
	const float DragFactor = FMath::Clamp(SubmergedVolumeCM3 / 10000.0f, 0.0f, 0.92f);
	return FMath::Clamp(1.0f - DragFactor, 0.08f, 1.0f);
}
