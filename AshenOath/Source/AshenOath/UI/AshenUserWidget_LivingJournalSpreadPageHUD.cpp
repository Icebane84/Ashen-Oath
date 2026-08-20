// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_LivingJournalSpreadPageHUD.h"

UAshenUserWidget_LivingJournalSpreadPageHUD::UAshenUserWidget_LivingJournalSpreadPageHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CurrentJitterIntensity = 0.0f;
}

void UAshenUserWidget_LivingJournalSpreadPageHUD::PopulateJournalPage(
	const FString& CoreText,
	const TArray<FMarginaliaEntry>& MarginaliaEntries,
	float InkJitterIntensity)
{
	KaelenCoreProse = CoreText;
	ActiveEntries = MarginaliaEntries;
	CurrentJitterIntensity = FMath::Clamp(InkJitterIntensity, 0.0f, 1.0f);
}

void UAshenUserWidget_LivingJournalSpreadPageHUD::ClearJournalPage()
{
	KaelenCoreProse.Empty();
	ActiveEntries.Empty();
	CurrentJitterIntensity = 0.0f;
}
