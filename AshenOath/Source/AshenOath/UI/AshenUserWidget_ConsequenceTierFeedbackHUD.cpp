// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_ConsequenceTierFeedbackHUD.h"

void UAshenUserWidget_ConsequenceTierFeedbackHUD::DisplayTierFeedback(EConsequenceProfileTier InTier, FName InEncounter)
{
	ActiveTier = InTier;
	DisplayedEncounterName = InEncounter;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_ConsequenceTierFeedbackHUD: Consequence Tier %d displayed for %s."),
		static_cast<int32>(ActiveTier), *DisplayedEncounterName.ToString());
}
