// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_CrisisHesitationHUD.h"

void UAshenUserWidget_CrisisHesitationHUD::UpdateOcularShadowDisplay(float VignetteAlpha)
{
	PeripheralOcularShadowAlpha = FMath::Clamp(VignetteAlpha, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_CrisisHesitationHUD: Refreshed peripheral ocular shadow vignette alpha to %f"), PeripheralOcularShadowAlpha);
}
