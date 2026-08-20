// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_PostureAlignmentHUD.generated.h"

/**
 * UAshenUserWidget_PostureAlignmentHUD
 * UMG backing widget presenting posture stance alignment visual gauge and balance telemetry.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_PostureAlignmentHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float PostureAlignmentGaugePercent = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdatePostureAlignmentGaugeDisplay(float AlignmentScalar);
};
