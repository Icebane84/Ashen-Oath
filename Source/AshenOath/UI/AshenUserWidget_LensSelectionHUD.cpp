// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_LensSelectionHUD.h"

void UAshenUserWidget_LensSelectionHUD::DisplayLensSelection(bool bVisible, bool bForcedCollapse)
{
	if (bForcedCollapse)
	{
		bIsLensSelectionVisible = false;
		UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_LensSelectionHUD: Forced Collapse active! Lens selection UI suppressed."));
		return;
	}

	bIsLensSelectionVisible = bVisible;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_LensSelectionHUD: Lens Selection UI %s."),
		bIsLensSelectionVisible ? TEXT("OPENED") : TEXT("CLOSED"));
}
