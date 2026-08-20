// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 234: Ashen Boss Phase Banner UMG Widget

#include "AshenUserWidget_BossPhaseBanner.h"

void UAshenUserWidget_BossPhaseBanner::DisplayPhaseBanner(int32 PhaseIndex, const FText& PhaseTitleText)
{
	ActivePhaseIndex = PhaseIndex;
	ActivePhaseTitle = PhaseTitleText;
	bBannerActive = true;

	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_BossPhaseBanner: BOSS PHASE BANNER — Phase %d: '%s'."),
		PhaseIndex, *PhaseTitleText.ToString());
}

void UAshenUserWidget_BossPhaseBanner::DismissPhaseBanner()
{
	bBannerActive = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_BossPhaseBanner: Boss phase banner dismissed."));
}
