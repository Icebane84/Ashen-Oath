// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_TraumaPaydownFeedbackHUD.h"

void UAshenUserWidget_TraumaPaydownFeedbackHUD::ShowTraumaResolution(float DebtCleared, float BurnoutCleansed)
{
	DisplayedDebtCleared = DebtCleared;
	DisplayedBurnoutCleansed = BurnoutCleansed;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_TraumaPaydownFeedbackHUD: Feedback HUD active — Debt Cleared: %.1f | Burnout Cleansed: %.1f"),
		DisplayedDebtCleared, DisplayedBurnoutCleansed);
}
