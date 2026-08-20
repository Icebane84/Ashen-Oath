// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 219: Ashen Soul Perk Tooltip UMG Widget

#include "AshenUserWidget_SoulPerkTooltip.h"

void UAshenUserWidget_SoulPerkTooltip::DisplayPerkTooltip(
	FName PerkID,
	const FText& Title,
	const FText& Description,
	float AshCost,
	bool bIsUnlocked,
	bool bPrereqMet)
{
	DisplayedPerkID = PerkID;
	DisplayedTitle = Title;
	DisplayedDescription = Description;
	DisplayedAshCost = AshCost;
	bPerkUnlocked = bIsUnlocked;
	bPrerequisitesMet = bPrereqMet;
	bTooltipVisible = true;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_SoulPerkTooltip: Tooltip displayed for perk '%s' ('%s') — %.0f Ash."),
		*PerkID.ToString(), *Title.ToString(), AshCost);
}

void UAshenUserWidget_SoulPerkTooltip::HideTooltip()
{
	bTooltipVisible = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_SoulPerkTooltip: Tooltip hidden."));
}
