// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_LivingJournalHUD.h"

void UAshenUserWidget_LivingJournalHUD::PopulateJournalPage(const FJournalResolutionEntry& Entry, bool bPerkUnlocked)
{
	DisplayedBestiaryID = Entry.BestiaryEntryID;
	DisplayedKaelenProse = Entry.KaelenEntryText;
	DisplayedGarrettSketchNote = Entry.GarrettMarginNote;
	DisplayedSerafinaLeafScript = Entry.SerafinaMarginNote;
	bHasUnlockedPerk = bPerkUnlocked;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_LivingJournalHUD: Populated Journal Page for '%s' (Perk Unlocked: %s)"),
		*DisplayedBestiaryID.ToString(), bHasUnlockedPerk ? TEXT("YES") : TEXT("NO"));
}
