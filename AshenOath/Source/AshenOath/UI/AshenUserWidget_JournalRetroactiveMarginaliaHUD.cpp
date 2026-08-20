// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_JournalRetroactiveMarginaliaHUD.h"

UAshenUserWidget_JournalRetroactiveMarginaliaHUD::UAshenUserWidget_JournalRetroactiveMarginaliaHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ActiveRenderedCount = 0;
}

void UAshenUserWidget_JournalRetroactiveMarginaliaHUD::DisplayMarginaliaEntries(const TArray<FRetroactiveMarginaliaEntry>& Entries)
{
	ActiveRenderedCount = Entries.Num();
}
