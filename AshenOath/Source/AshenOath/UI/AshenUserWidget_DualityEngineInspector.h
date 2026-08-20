// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_DualityEngineInspector.generated.h"

/**
 * UAshenUserWidget_DualityEngineInspector
 * UMG backing widget inspecting Duality Engine material parameter values (R: Soot, G: Seam Grime, B: Raggedness, A: Emissive).
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_DualityEngineInspector : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float DisplayedCorruptionScalar = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void DisplayDualityShaderTelemetry(float CorruptionScalar, float Soot, float SeamGrime);
};
