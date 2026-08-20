// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenSomaticCompanionReactivityAdapter.h"

UAshenSomaticCompanionReactivityAdapter::UAshenSomaticCompanionReactivityAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenSomaticCompanionReactivityAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenSomaticCompanionReactivityAdapter::TriggerFatigueCallout(FName CompanionID, float StaminaPercent)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticCompanionReactivityAdapter: %s callout for fatigue (%.1f%% stamina) ('Steady yourself Kaelen, catch your breath!')"),
		*CompanionID.ToString(), StaminaPercent * 100.0f);
}
