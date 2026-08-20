// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 274: Ashen Dungeon Keycard Notification UMG Widget

#include "AshenUserWidget_DungeonKeycardNotification.h"

void UAshenUserWidget_DungeonKeycardNotification::DisplayKeycardAcquiredNotification(FName KeycardID, const FText& KeycardNameText)
{
	AcquiredKeycardID = KeycardID;
	AcquiredKeycardName = KeycardNameText;
	bNotificationActive = true;

	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_DungeonKeycardNotification: KEYCARD ACQUIRED BANNER — '%s' ('%s')."),
		*KeycardID.ToString(), *KeycardNameText.ToString());
}

void UAshenUserWidget_DungeonKeycardNotification::DismissNotification()
{
	bNotificationActive = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_DungeonKeycardNotification: Keycard notification banner dismissed."));
}
