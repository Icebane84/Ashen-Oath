// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 264: Ashen Pressure Plate Status UMG Widget

#include "AshenUserWidget_PressurePlateStatus.h"

void UAshenUserWidget_PressurePlateStatus::UpdatePlatePuzzleStatus(int32 ActivePlates, int32 RequiredPlates, bool bPuzzleSolved)
{
	DepressedPlateCount = ActivePlates;
	RequiredPlateCount = RequiredPlates;
	bPuzzleComplete = bPuzzleSolved;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_PressurePlateStatus: Puzzle status updated — %d / %d plates depressed. Solved: %s."),
		ActivePlates, RequiredPlates, bPuzzleSolved ? TEXT("TRUE") : TEXT("FALSE"));
}
