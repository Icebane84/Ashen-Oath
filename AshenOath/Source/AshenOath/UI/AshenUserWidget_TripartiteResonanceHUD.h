// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenTripartiteResonanceTypes.h"
#include "AshenUserWidget_TripartiteResonanceHUD.generated.h"

/**
 * UAshenUserWidget_TripartiteResonanceHUD
 * 
 * UMG/Slate widget displaying the 3-ring resonance reticle and finisher prompt.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_TripartiteResonanceHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_TripartiteResonanceHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the displayed combo phase */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Trio")
	void UpdateComboDisplay(const FTripartiteComboState& State);

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Trio")
	ETripartiteComboPhase GetDisplayedPhase() const { return DisplayedPhase; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Trio")
	ETripartiteComboPhase DisplayedPhase = ETripartiteComboPhase::Inactive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Trio")
	float DisplayedRemainingTime = 0.0f;
};
