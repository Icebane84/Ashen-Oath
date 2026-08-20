// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 334: Ashen Vigil Travel Menu UMG Widget

#include "AshenUserWidget_VigilTravelMenu.h"

void UAshenUserWidget_VigilTravelMenu::UpdateVigilTravelDisplay(float CurrentVigilance, bool bExhausted)
{
	DisplayedVigilance = CurrentVigilance;
	bPartyExhausted = bExhausted;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_VigilTravelMenu: Vigilance Display updated -> %.1f%% (Exhausted: %s)."),
		CurrentVigilance, bExhausted ? TEXT("TRUE") : TEXT("FALSE"));
}
