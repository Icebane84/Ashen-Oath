// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_HeartstoneCrucibleHUD.h"

void UAshenUserWidget_HeartstoneCrucibleHUD::UpdateCrucibleRemnants(int32 RemnantCount)
{
	AvailableSoulRemnants = RemnantCount;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_HeartstoneCrucibleHUD: Available soul remnants: %d"), AvailableSoulRemnants);
}
