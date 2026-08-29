// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_ForensicDeductionBoardHUD.h"

UAshenUserWidget_ForensicDeductionBoardHUD::UAshenUserWidget_ForensicDeductionBoardHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedCaseId = NAME_None;
	DisplayedPinnedCount = 0;
	DisplayedSynthesisScore = 0.0f;
	DisplayedState = EMemoryReconstructionState::UnsolvedFragments;
}

void UAshenUserWidget_ForensicDeductionBoardHUD::UpdateDeductionBoard(
	FName ActiveCaseId,
	int32 PinnedCount,
	float SynthesisScore,
	EMemoryReconstructionState State)
{
	DisplayedCaseId = ActiveCaseId;
	DisplayedPinnedCount = PinnedCount;
	DisplayedSynthesisScore = SynthesisScore;
	DisplayedState = State;
}
