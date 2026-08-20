// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Companions/AshenTransferenceBurnoutTypes.h"
#include "AshenUserWidget_TransferenceAuraOverlayHUD.generated.h"

/**
 * UAshenUserWidget_TransferenceAuraOverlayHUD
 * 
 * UMG/Slate overlay rendering golden tether links between Kaelen and Serafina,
 * with ash-soot vignetting on heavy burnout.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_TransferenceAuraOverlayHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_TransferenceAuraOverlayHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates overlay visual parameters */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Transference")
	void UpdateTransferenceVisuals(float BurnoutRatio, float TetherIntensity);

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Transference")
	float GetAuraDimmingScalar() const { return CurrentAuraDimming; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Transference")
	float CurrentBurnoutRatio = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Transference")
	float CurrentTetherIntensity = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Transference")
	float CurrentAuraDimming = 1.0f;
};
