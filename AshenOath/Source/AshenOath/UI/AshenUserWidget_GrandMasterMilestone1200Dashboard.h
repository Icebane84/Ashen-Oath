// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_GrandMasterMilestone1200Dashboard.generated.h"

/**
 * UAshenUserWidget_GrandMasterMilestone1200Dashboard
 * 👑 GRAND MASTER MILESTONE 1200 UMG DASHBOARD WIDGET — Visualizing Inner World memory battle telemetry and 1,200 build ascension metrics.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_GrandMasterMilestone1200Dashboard : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 TotalCleanBuildsCount = 1200;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void DisplayGrandMasterMilestone1200Metrics();
};
