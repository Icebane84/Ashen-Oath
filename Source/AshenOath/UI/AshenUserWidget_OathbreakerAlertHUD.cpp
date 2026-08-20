// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_OathbreakerAlertHUD.h"

void UAshenUserWidget_OathbreakerAlertHUD::TriggerOathbreakerAlert(EAshenLivingOathType BrokenOath)
{
	bIsAlertActive = true;
	FracturedOath = BrokenOath;
	UE_LOG(LogTemp, Error, TEXT("UAshenUserWidget_OathbreakerAlertHUD: OATHBREAKER ALERT! Fractured Oath: %d"), (int32)FracturedOath);
}
