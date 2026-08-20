// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 318: Ashen Living Oath Status UMG Widget

#include "AshenUserWidget_LivingOathStatus.h"

void UAshenUserWidget_LivingOathStatus::UpdateLivingOathDisplay(FName OathPactID, bool bIsActive)
{
	DisplayedOathPactID = OathPactID;
	bOathBound = bIsActive;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_LivingOathStatus: Living Oath display updated — '%s' (Bound: %s)."),
		*OathPactID.ToString(), bIsActive ? TEXT("TRUE") : TEXT("FALSE"));
}
