// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenUserWidget_MindscapeDebtWarningOverlay.generated.h"

/**
 * UAshenUserWidget_MindscapeDebtWarningOverlay
 * UMG widget backing class displaying screen edge distortion when IntegrationDebt >= 0.75.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_MindscapeDebtWarningOverlay : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void OnSoulStateInvalidated(const FSoulStateVector& StateVector);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	float GetVignetteDistortionOpacity() const { return VignetteDistortionOpacity; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|UI")
	float VignetteDistortionOpacity = 0.0f;
};
