// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_LivingParchmentMapHUD.h"

void UAshenUserWidget_LivingParchmentMapHUD::RefreshMapPins(const TArray<FJournalMapPin>& InPins)
{
	RenderedPins = InPins;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_LivingParchmentMapHUD: Refreshed Living Parchment Map with %d Pins."), RenderedPins.Num());
}
