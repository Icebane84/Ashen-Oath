// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenCameraResistanceDilationComponent.h"

UAshenCameraResistanceDilationComponent::UAshenCameraResistanceDilationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenCameraResistanceDilationComponent::CalculateCompressedFOV(float SubmergedVolumeCM3) const
{
	if (SubmergedVolumeCM3 <= 0.0f)
	{
		return 90.0f;
	}

	// Dynamic FOV compression from 90 deg down to 76 deg
	const float Compression = FMath::Clamp((SubmergedVolumeCM3 / 10000.0f) * 14.0f, 0.0f, 14.0f);
	return 90.0f - Compression;
}
