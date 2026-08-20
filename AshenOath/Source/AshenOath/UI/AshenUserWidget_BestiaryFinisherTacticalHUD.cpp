// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_BestiaryFinisherTacticalHUD.h"

void UAshenUserWidget_BestiaryFinisherTacticalHUD::DisplayWeakspotPrompt(FName WeakspotName, EAshenPartyFinisherType FinisherType)
{
	TargetedWeakspotName = WeakspotName;
	ActiveBestiaryFinisher = FinisherType;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_BestiaryFinisherTacticalHUD: Displaying weakspot '%s' for Finisher Type %d."),
		*TargetedWeakspotName.ToString(), (int32)ActiveBestiaryFinisher);
}
