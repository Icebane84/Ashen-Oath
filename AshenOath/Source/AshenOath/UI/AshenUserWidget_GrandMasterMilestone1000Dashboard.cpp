// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_GrandMasterMilestone1000Dashboard.h"

void UAshenUserWidget_GrandMasterMilestone1000Dashboard::RefreshGrandMasterDashboardDisplay()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_GrandMasterMilestone1000Dashboard: Refreshed Grand Master Dashboard telemetry display (%d builds clean, %d ProductFilter tests passed)."), VerifiedBuildCount, TotalPassedTestsCount);
}
