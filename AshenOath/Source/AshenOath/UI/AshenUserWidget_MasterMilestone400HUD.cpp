// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 398: Ashen Master Milestone 400 HUD UMG Widget

#include "AshenUserWidget_MasterMilestone400HUD.h"

void UAshenUserWidget_MasterMilestone400HUD::UpdateMasterDashboardDisplay(int32 TotalBuildsCount, int32 TotalQATestsCount)
{
	TotalBuilds = TotalBuildsCount;
	TotalQATests = TotalQATestsCount;

	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_MasterMilestone400HUD: MASTER HUD DASHBOARD UPDATED — %d BUILDS CLEAN (%d QA Tests Active)."),
		TotalBuildsCount, TotalQATestsCount);
}
