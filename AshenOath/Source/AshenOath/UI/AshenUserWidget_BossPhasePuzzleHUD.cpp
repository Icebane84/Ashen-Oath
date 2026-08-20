// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_BossPhasePuzzleHUD.h"

void UAshenUserWidget_BossPhasePuzzleHUD::UpdateBossPhaseHUD(EBossPuzzlePhase NewPhase)
{
	DisplayedBossPhase = NewPhase;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_BossPhasePuzzleHUD: Displayed Boss Puzzle Phase: %d"),
		static_cast<int32>(DisplayedBossPhase));
}
