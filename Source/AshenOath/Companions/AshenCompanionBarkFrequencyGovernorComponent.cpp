// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenCompanionBarkFrequencyGovernorComponent.h"

UAshenCompanionBarkFrequencyGovernorComponent::UAshenCompanionBarkFrequencyGovernorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenCompanionBarkFrequencyGovernorComponent::CanPlayBarkCategory(FName BarkCategory, float CurrentGameTime)
{
	float* LastTime = LastBarkPlayTimes.Find(BarkCategory);
	if (!LastTime || (CurrentGameTime - *LastTime) >= 8.0f)
	{
		LastBarkPlayTimes.Add(BarkCategory, CurrentGameTime);
		UE_LOG(LogTemp, Log, TEXT("UAshenCompanionBarkFrequencyGovernorComponent: Allowed bark category '%s' at time %.1fs"), *BarkCategory.ToString(), CurrentGameTime);
		return true;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionBarkFrequencyGovernorComponent: Suppressed bark category '%s' due to governor cooldown"), *BarkCategory.ToString());
	return false;
}
