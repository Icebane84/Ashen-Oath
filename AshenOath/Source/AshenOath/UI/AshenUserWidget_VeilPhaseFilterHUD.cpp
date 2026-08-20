// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_VeilPhaseFilterHUD.h"

void UAshenUserWidget_VeilPhaseFilterHUD::UpdateVeilFilterGaugeDisplay(float FilterIntensity)
{
	VeilPhaseFilterGaugePercent = FMath::Clamp(FilterIntensity, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_VeilPhaseFilterHUD: Refreshed veil phase filter HUD display to %f%%"), VeilPhaseFilterGaugePercent * 100.0f);
}
