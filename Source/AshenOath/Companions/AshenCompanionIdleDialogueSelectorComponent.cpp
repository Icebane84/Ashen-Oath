// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenCompanionIdleDialogueSelectorComponent.h"

UAshenCompanionIdleDialogueSelectorComponent::UAshenCompanionIdleDialogueSelectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FName UAshenCompanionIdleDialogueSelectorComponent::SelectCompanionIdleBark(const FSoulStateVector& StateVector, float CompanionTrust, const FString& RegionID)
{
	if (StateVector.Corruption > 0.7f)
	{
		return FName("Bark_UneaseAtCorruption");
	}
	else if (CompanionTrust >= 0.8f)
	{
		return FName("Bark_SwornLoyalty");
	}
	return FName("Bark_GeneralObservations");
}
