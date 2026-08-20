// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Companions/AshenSomaticSilenceTypes.h"
#include "AshenUserWidget_WordlessResonanceHUD.generated.h"

/**
 * UAshenUserWidget_WordlessResonanceHUD
 * 
 * Minimalist UI widget displaying subtle breathing reticle stabilization
 * and quiet solidarity indicators.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_WordlessResonanceHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_WordlessResonanceHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates silence HUD state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Silence")
	void UpdateSilencePresentation(ESomaticSilenceClassification Classification, float Confidence);

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Silence")
	float GetReticleStabilityScalar() const { return CurrentStability; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Silence")
	ESomaticSilenceClassification CurrentSilenceType = ESomaticSilenceClassification::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Silence")
	float CurrentStability = 1.0f;
};
