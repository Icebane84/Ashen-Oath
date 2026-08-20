// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_VeilPhaseGaugeHUD.h"

void UAshenUserWidget_VeilPhaseGaugeHUD::UpdateVeilGaugeDisplay(float PhaseIntensity)
{
	VeilPhaseGaugePercent = FMath::Clamp(PhaseIntensity, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_VeilPhaseGaugeHUD: Updated veil phase gauge display to %f%%"), VeilPhaseGaugePercent * 100.0f);
}
