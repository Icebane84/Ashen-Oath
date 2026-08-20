// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 626: Ashen User Widget Contested Interpretation

#include "AshenUserWidget_ContestedInterpretation.h"

void UAshenUserWidget_ContestedInterpretation::DisplayContestedInterpretation(FName MemoryID, FText RawEvent, FText ContestedText, bool bIsFragmenting)
{
	ActiveMemoryID = MemoryID;
	DisplayedRawEventText = RawEvent;
	DisplayedContestedText = ContestedText;
	bIsActivePassFragmenting = bIsFragmenting;

	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_ContestedInterpretation: CONTESTED INTERPRETATION DISPLAYED -> Memory '%s' | Pass: %s."),
		*MemoryID.ToString(), bIsFragmenting ? TEXT("FRAGMENTATION (Whispering Void)") : TEXT("INTEGRATIVE (Memory Weaving)"));
}
