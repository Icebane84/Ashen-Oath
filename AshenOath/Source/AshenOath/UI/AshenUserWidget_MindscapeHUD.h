// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_MindscapeHUD.generated.h"

/**
 * UAshenUserWidget_MindscapeHUD
 *
 * UMG backing widget rendering visual telemetry for Mindscape stability & hallucination intensity.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_MindscapeHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateMindscapeHUDDisplay(FName MindscapeID, float DistortionIntensity);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedMindscapeID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedDistortionIntensity = 0.0f;
};
