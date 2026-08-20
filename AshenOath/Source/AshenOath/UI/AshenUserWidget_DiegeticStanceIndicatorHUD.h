// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenUserWidget_DiegeticStanceIndicatorHUD.generated.h"

/**
 * UAshenUserWidget_DiegeticStanceIndicatorHUD
 * UMG widget backing class displaying diegetic combat stance icon with psychological flicker.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_DiegeticStanceIndicatorHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void OnSoulStateInvalidated(const FSoulStateVector& StateVector);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	float GetStanceIconOpacityFlicker() const { return StanceIconOpacityFlicker; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|UI")
	float StanceIconOpacityFlicker = 1.0f;
};
