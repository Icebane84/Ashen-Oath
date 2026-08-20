// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenUserWidget_DiegeticCompassPhenotypeHUD.generated.h"

/**
 * UAshenUserWidget_DiegeticCompassPhenotypeHUD
 * UMG widget backing class for diegetic compass displaying psychological needle jitter.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_DiegeticCompassPhenotypeHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void OnSoulStateInvalidated(const FSoulStateVector& StateVector);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	float GetCompassNeedleJitterAngleOffset() const { return CompassNeedleJitterAngleOffset; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|UI")
	float CompassNeedleJitterAngleOffset = 0.0f;
};
