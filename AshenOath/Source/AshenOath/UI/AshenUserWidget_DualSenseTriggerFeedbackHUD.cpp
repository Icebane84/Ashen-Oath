// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_DualSenseTriggerFeedbackHUD.h"

void UAshenUserWidget_DualSenseTriggerFeedbackHUD::UpdateTriggerFeedbackHUD(const FHapticFrictionProfile& Profile)
{
	DisplayedTriggerResistance = Profile.TriggerResistance;
	DisplayedLeftFrequency = Profile.LeftFrequencyHz;
	DisplayedRightFrequency = Profile.RightFrequencyHz;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_DualSenseTriggerFeedbackHUD: Trigger Feedback HUD -> Resistance: %d, Left: %.1fHz, Right: %.1fHz"),
		DisplayedTriggerResistance, DisplayedLeftFrequency, DisplayedRightFrequency);
}
