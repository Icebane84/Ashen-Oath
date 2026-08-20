// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_PostureAlignmentInspector.generated.h"

/**
 * UAshenUserWidget_PostureAlignmentInspector
 * UMG backing widget inspecting posture stance alignment parameters and balance telemetry.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_PostureAlignmentInspector : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float PostureAlignmentPercent = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void RefreshPostureAlignmentDisplay(float AlignmentScalar);
};
