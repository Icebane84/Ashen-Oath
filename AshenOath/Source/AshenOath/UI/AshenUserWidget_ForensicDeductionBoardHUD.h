// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Narrative/AshenForensicMindscapeTypes.h"
#include "AshenUserWidget_ForensicDeductionBoardHUD.generated.h"

/**
 * UAshenUserWidget_ForensicDeductionBoardHUD
 * 
 * Renders the Forensic Journal deduction board: Pinned clue nodes, connective yarn threads, contradiction markers, and circular synthesis meter.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ForensicDeductionBoardHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_ForensicDeductionBoardHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the deduction board UI */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Forensic")
	void UpdateDeductionBoard(
		FName ActiveCaseId,
		int32 PinnedCount,
		float SynthesisScore,
		EMemoryReconstructionState State);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Forensic")
	FName DisplayedCaseId = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Forensic")
	int32 DisplayedPinnedCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Forensic")
	float DisplayedSynthesisScore = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Forensic")
	EMemoryReconstructionState DisplayedState = EMemoryReconstructionState::UnsolvedFragments;
};
