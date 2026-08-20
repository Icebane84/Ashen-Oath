// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 447: Ashen Narrative Choice UI UMG Widget

#include "AshenUserWidget_NarrativeChoiceUI.h"

void UAshenUserWidget_NarrativeChoiceUI::UpdateNarrativeChoiceDisplay(FName NodeID, int32 SelectedOption)
{
	DisplayedNodeID = NodeID;
	DisplayedSelectedOption = SelectedOption;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_NarrativeChoiceUI: Narrative Choice UI updated — Node '%s' (Option %d)."),
		*NodeID.ToString(), SelectedOption);
}
