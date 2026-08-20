// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 214: Ashen Fast Travel Notification UMG Widget

#include "AshenUserWidget_FastTravelNotification.h"

void UAshenUserWidget_FastTravelNotification::DisplaySanctuaryUnlockedNotification(FName SanctuaryID, const FText& SanctuaryName)
{
	DisplayedSanctuaryID = SanctuaryID;
	DisplayedSanctuaryName = SanctuaryName;
	bNotificationActive = true;

	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_FastTravelNotification: SANCTUARY UNLOCKED BANNER — '%s' ('%s')."),
		*SanctuaryID.ToString(), *SanctuaryName.ToString());
}

void UAshenUserWidget_FastTravelNotification::DismissNotification()
{
	bNotificationActive = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_FastTravelNotification: Notification banner dismissed."));
}
