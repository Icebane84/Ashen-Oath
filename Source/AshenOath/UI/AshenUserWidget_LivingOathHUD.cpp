// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_LivingOathHUD.h"

void UAshenUserWidget_LivingOathHUD::UpdateLivingOathHUD(EAshenLivingOathType OathType, float Fulfillment)
{
	DisplayedOathType = OathType;
	FulfillmentRatio = FMath::Clamp(Fulfillment, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_LivingOathHUD: Living Oath Type %d displayed (Fulfillment: %.1f%%)."),
		(int32)DisplayedOathType, FulfillmentRatio * 100.0f);
}
