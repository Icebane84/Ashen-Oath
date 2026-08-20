// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenShadowMarkSurgeGASAbility.h"

UAshenShadowMarkSurgeGASAbility::UAshenShadowMarkSurgeGASAbility()
{
	DarkDamageMultiplier = 1.40f;
	SurgeDuration = 10.0f;
	MinCorruptionRequired = 0.70f;
}

bool UAshenShadowMarkSurgeGASAbility::UnleashShadowMarkSurge(AActor* InstigatorActor, float CurrentCorruption)
{
	if (!InstigatorActor || CurrentCorruption < MinCorruptionRequired) return false;

	UE_LOG(LogTemp, Warning, TEXT("UAshenShadowMarkSurgeGASAbility: UNLEASHED SHADOW MARK SURGE (Multiplier: %.2fx, Duration: %.1fs, Corruption: %.2f)!"),
		DarkDamageMultiplier, SurgeDuration, CurrentCorruption);

	return true;
}
