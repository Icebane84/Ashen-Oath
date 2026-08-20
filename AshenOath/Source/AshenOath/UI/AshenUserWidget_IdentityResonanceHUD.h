// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_IdentityResonanceHUD.generated.h"

/**
 * UAshenUserWidget_IdentityResonanceHUD
 * UMG backing widget presenting somatic identity resonance visual gauge and telemetry.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_IdentityResonanceHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float IdentityResonanceGaugePercent = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateIdentityResonanceDisplay(float ResonanceScalar);
};
