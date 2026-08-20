// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 294: Ashen Trap Chest Warning UMG Widget

#include "AshenUserWidget_TrapChestWarning.h"

void UAshenUserWidget_TrapChestWarning::DisplayTrapWarning(const FText& WarningText)
{
	DisplayedWarningText = WarningText;
	bWarningActive = true;

	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_TrapChestWarning: TRAP WARNING DISPLAYED — '%s'."), *WarningText.ToString());
}

void UAshenUserWidget_TrapChestWarning::DismissWarning()
{
	bWarningActive = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_TrapChestWarning: Trap warning dismissed."));
}
