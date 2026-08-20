// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_FacialMorphHUD.generated.h"

/**
 * UAshenUserWidget_FacialMorphHUD
 *
 * UMG backing widget rendering visual telemetry for active facial morph weights.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_FacialMorphHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateFacialMorphHUDDisplay(float PainWeight, float ExhaustionWeight);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedPainWeight = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedExhaustionWeight = 0.0f;
};
