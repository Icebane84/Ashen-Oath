// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "AshenUserWidget_OathbringerStanceMatrixHUD.generated.h"

/**
 * UAshenUserWidget_OathbringerStanceMatrixHUD
 * 
 * Renders the 4-guard directional stance diamond (Up: Vom Tag, Down: Pflug, Left: Ochs, Right: Mordhau), active runic seam color, and Flow Glint timing gauge.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_OathbringerStanceMatrixHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_OathbringerStanceMatrixHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the displayed stance telemetry */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Stance")
	void UpdateStanceHUD(
		EOathbringerMartialStance ActiveStance,
		FLinearColor SeamColor,
		float FlowCharge,
		bool bFlowGlintActive);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Stance")
	EOathbringerMartialStance DisplayedStance = EOathbringerMartialStance::VomTag_HighWrath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Stance")
	FLinearColor DisplayedSeamColor = FLinearColor(1.0f, 0.15f, 0.05f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Stance")
	float DisplayedFlowCharge = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Stance")
	bool bDisplayedFlowGlint = false;
};
