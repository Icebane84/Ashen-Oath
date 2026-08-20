// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 659: Ashen Trinity Doctrine Companion Synergy Component

#include "AshenTrinityDoctrineCompanionSynergyComponent.h"

UAshenTrinityDoctrineCompanionSynergyComponent::UAshenTrinityDoctrineCompanionSynergyComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	TotalSynergiesExecuted = 0;
}

void UAshenTrinityDoctrineCompanionSynergyComponent::TriggerCompanionSynergy(FName CompanionID, bool bIsKaelenUnbroken)
{
	if (CompanionID.IsNone()) return;

	TotalSynergiesExecuted++;
	const float Multiplier = bIsKaelenUnbroken ? 1.5f : 1.0f;
	const FName ActionTag = (CompanionID == FName(TEXT("Garrett")))
		? FName(TEXT("Action.TacticalFlankIntercept"))
		: FName(TEXT("Action.HarmonicPurification"));

	OnSynergyTriggered.Broadcast(CompanionID, ActionTag, Multiplier);

	UE_LOG(LogTemp, Warning, TEXT("UAshenTrinityDoctrineCompanionSynergyComponent: TRINITY SYNERGY TRIGGERED -> Companion '%s' | Action '%s' | Multiplier: %.2fx (Total: %d)."),
		*CompanionID.ToString(), *ActionTag.ToString(), Multiplier, TotalSynergiesExecuted);
}
