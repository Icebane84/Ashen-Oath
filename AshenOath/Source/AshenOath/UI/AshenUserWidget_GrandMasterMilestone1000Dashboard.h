// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_GrandMasterMilestone1000Dashboard.generated.h"

/**
 * UAshenUserWidget_GrandMasterMilestone1000Dashboard
 * Monumental UMG HUD dashboard presenting live telemetry across all 1,000 builds, 12 vertical slices, and FSoulStateVector metrics.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_GrandMasterMilestone1000Dashboard : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 VerifiedBuildCount = 1000;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 TotalPassedTestsCount = 800;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void RefreshGrandMasterDashboardDisplay();
};
