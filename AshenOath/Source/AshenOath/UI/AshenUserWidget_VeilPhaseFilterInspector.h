// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_VeilPhaseFilterInspector.generated.h"

/**
 * UAshenUserWidget_VeilPhaseFilterInspector
 * UMG backing widget inspecting veil phase filter parameters and mesh distortion telemetry.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_VeilPhaseFilterInspector : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float VeilPhaseFilterPercent = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void RefreshVeilPhaseFilterDisplay(float FilterValue);
};
