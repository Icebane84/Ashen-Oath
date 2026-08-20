// AshenUserWidget_LensSelection.h
// Copyright Ashen Oath. All rights reserved.
// PHOENIX CODEX: ENGINE-SPEC-001 (DEFINITIVE CANON)
// The Lens Selection UI presented during Heartstone rest & Mindscape entry.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenSoulStateVector.h"
#include "AshenUserWidget_LensSelection.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLensConfirmedSignature, EInterpretiveLens, SelectedLens);

/**
 * @class UAshenUserWidget_LensSelection
 * @brief UserWidget base class for the radial/interactive Lens Selection menu.
 *
 * Allows player to choose between Accountability, Grace, and Utility lenses
 * during the Heartstone Integration Ritual. Calls USoulConstellationSubsystem::FinalizeIntegration().
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_LensSelection : public UUserWidget
{
	GENERATED_BODY()

public:
	// --- Public API ---------------------------------------------------------

	/** Set active focused lens choice without confirming. */
	UFUNCTION(BlueprintCallable, Category = "Soul Constellation | Lens UI")
	void SelectLensOption(EInterpretiveLens Lens);

	/** Confirm current lens selection and finalize integration through the Kernel. */
	UFUNCTION(BlueprintCallable, Category = "Soul Constellation | Lens UI")
	void ConfirmLensSelection();

	/** Returns currently selected lens option. */
	UFUNCTION(BlueprintPure, Category = "Soul Constellation | Lens UI")
	EInterpretiveLens GetSelectedLens() const { return CurrentSelectedLens; }

	// --- Blueprint Implementable Events ------------------------------------

	/** Event triggered when player hovers/selects a lens option (for visual feedback). */
	UFUNCTION(BlueprintImplementableEvent, Category = "Soul Constellation | Lens UI")
	void OnLensOptionHovered(EInterpretiveLens Lens);

	/** Event triggered when lens selection is confirmed. */
	UPROPERTY(BlueprintAssignable, Category = "Soul Constellation | Lens UI")
	FOnLensConfirmedSignature OnLensConfirmed;

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soul Constellation | Lens UI")
	EInterpretiveLens CurrentSelectedLens = EInterpretiveLens::Accountability;
};
