// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_GrandMasterMilestone1100Dashboard.generated.h"

/**
 * UAshenUserWidget_GrandMasterMilestone1100Dashboard
 * UMG backing widget presenting Grand Master Milestone 1100 Sovereign Phoenix telemetry.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_GrandMasterMilestone1100Dashboard : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 TotalCleanBuildsCount = 1100;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void RefreshGrandMasterDashboardDisplay(int32 CleanBuilds);
};
