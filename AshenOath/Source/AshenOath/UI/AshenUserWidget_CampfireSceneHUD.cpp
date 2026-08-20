// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_CampfireSceneHUD.h"

void UAshenUserWidget_CampfireSceneHUD::SetCampfireHUDActive(bool bActive)
{
	bIsCampfireRestActive = bActive;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_CampfireSceneHUD: Campfire rest HUD %s."), bIsCampfireRestActive ? TEXT("OPENED") : TEXT("CLOSED"));
}
