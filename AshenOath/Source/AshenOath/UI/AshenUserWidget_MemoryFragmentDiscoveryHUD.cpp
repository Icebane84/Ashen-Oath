// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_MemoryFragmentDiscoveryHUD.h"

void UAshenUserWidget_MemoryFragmentDiscoveryHUD::DisplayFragmentPrompt(FName FragmentID, bool bVisible)
{
	DiscoveredFragmentID = FragmentID;
	bIsPromptVisible = bVisible;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_MemoryFragmentDiscoveryHUD: Fragment Prompt for '%s' %s."),
		*DiscoveredFragmentID.ToString(), bIsPromptVisible ? TEXT("DISPLAYED") : TEXT("HIDDEN"));
}
