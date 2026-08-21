// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_LivingJournalReaderHUD.h"

UAshenUserWidget_LivingJournalReaderHUD::UAshenUserWidget_LivingJournalReaderHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CurrentPageIndex = 0;
	DiscoveredNotesCount = 0;
}

void UAshenUserWidget_LivingJournalReaderHUD::NavigatePage(int32 DeltaPages)
{
	CurrentPageIndex = FMath::Max(0, CurrentPageIndex + DeltaPages);
}

void UAshenUserWidget_LivingJournalReaderHUD::InspectMarginaliaEntry(const FString& EntryId)
{
	DiscoveredNotesCount++;
}
