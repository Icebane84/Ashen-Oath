// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_MasterMilestone400HUD.generated.h"

/**
 * UAshenUserWidget_MasterMilestone400HUD
 *
 * UMG backing widget rendering the Master Systems Synergy HUD dashboard across all 5 Pillars.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_MasterMilestone400HUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateMasterDashboardDisplay(int32 TotalBuildsCount, int32 TotalQATestsCount);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 TotalBuilds = 400;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 TotalQATests = 200;
};
