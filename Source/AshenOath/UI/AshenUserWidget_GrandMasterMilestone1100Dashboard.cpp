// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_GrandMasterMilestone1100Dashboard.h"

void UAshenUserWidget_GrandMasterMilestone1100Dashboard::RefreshGrandMasterDashboardDisplay(int32 CleanBuilds)
{
	TotalCleanBuildsCount = CleanBuilds;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_GrandMasterMilestone1100Dashboard: Refreshed Grand Master Dashboard (%d builds clean)."), TotalCleanBuildsCount);
}
