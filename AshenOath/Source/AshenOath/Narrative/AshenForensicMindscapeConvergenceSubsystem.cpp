// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenForensicMindscapeConvergenceSubsystem.h"

UAshenForensicMindscapeConvergenceSubsystem::UAshenForensicMindscapeConvergenceSubsystem()
{
}

void UAshenForensicMindscapeConvergenceSubsystem::DiscoverClue(
	const FForensicClueRecord& Clue)
{
	if (!ClueRegistry.Contains(Clue.ClueId))
	{
		ClueRegistry.Add(Clue.ClueId, Clue);
		OnForensicClueDiscovered.Broadcast(Clue.ClueId, Clue);
	}
}

float UAshenForensicMindscapeConvergenceSubsystem::PinClueToCase(
	FName CaseId,
	FName ClueId)
{
	FMemoryPalaceDeductionBoard& Board = ActiveDeductionBoards.FindOrAdd(CaseId);
	Board.CaseId = CaseId;

	if (!Board.PinnedClueIds.Contains(ClueId))
	{
		Board.PinnedClueIds.Add(ClueId);
	}

	// Calculate synthesis index (Each valid pinned clue adds weight toward 1.0)
	Board.SynthesisIndex = FMath::Clamp(static_cast<float>(Board.PinnedClueIds.Num()) * 0.35f, 0.0f, 1.0f);
	Board.State = (Board.SynthesisIndex >= 0.85f) ? EMemoryReconstructionState::ReconstructedTruth : EMemoryReconstructionState::DeductionInProgress;

	OnMemoryDeductionBoardUpdated.Broadcast(CaseId, Board.SynthesisIndex);
	return Board.SynthesisIndex;
}

FReconstructedMemoryResult UAshenForensicMindscapeConvergenceSubsystem::SynthesizeCase(
	FName CaseId)
{
	FReconstructedMemoryResult Result;
	Result.CaseId = CaseId;
	Result.bCaseSolved = false;
	Result.SanityRestored = 0.0f;
	Result.FactionCritDamageBonus = 0.0f;

	if (FMemoryPalaceDeductionBoard* Board = ActiveDeductionBoards.Find(CaseId))
	{
		if (Board->SynthesisIndex >= 0.85f)
		{
			Result.bCaseSolved = true;
			Result.SanityRestored = 50.0f; // +50 Sanity Catharsis
			Result.FactionCritDamageBonus = 0.25f; // +25% Crit Damage
			Result.EpiphanyLoreSummary = FText::FromString(TEXT("Case Synthesized: The physical autopsy disproved the church dogma. Truth restored."));

			Board->State = EMemoryReconstructionState::ReconstructedTruth;
			SolvedCases.Add(CaseId, Result);

			OnMemoryPalaceCaseSolved.Broadcast(CaseId, Result);
		}
	}

	return Result;
}

bool UAshenForensicMindscapeConvergenceSubsystem::IsCaseSolved(
	FName CaseId) const
{
	return SolvedCases.Contains(CaseId);
}
