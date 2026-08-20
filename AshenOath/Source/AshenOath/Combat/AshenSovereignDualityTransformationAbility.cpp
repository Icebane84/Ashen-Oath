// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenSovereignDualityTransformationAbility.h"

UAshenSovereignDualityTransformationAbility::UAshenSovereignDualityTransformationAbility()
{
}

bool UAshenSovereignDualityTransformationAbility::TriggerDualityTransformationPulse()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenSovereignDualityTransformationAbility: Triggered real-time Duality Transformation pulse (Radius: %f)."), TransformationPulseRadius);
	return true;
}
