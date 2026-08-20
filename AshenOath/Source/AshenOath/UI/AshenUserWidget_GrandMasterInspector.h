// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_GrandMasterInspector.generated.h"

/**
 * UAshenUserWidget_GrandMasterInspector
 * UMG backing widget inspecting Grand Master Milestone 1100 synthesis parameters and build telemetry.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_GrandMasterInspector : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 TotalInspectedBuilds = 1100;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void RefreshGrandMasterInspectorDisplay(int32 BuildCount);
};
