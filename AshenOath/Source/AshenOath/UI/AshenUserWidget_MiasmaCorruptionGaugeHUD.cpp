// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_MiasmaCorruptionGaugeHUD.h"

void UAshenUserWidget_MiasmaCorruptionGaugeHUD::UpdateMiasmaGaugeDisplay(float NewCorruptionLevel)
{
	MiasmaGaugePercent = FMath::Clamp(NewCorruptionLevel / 100.0f, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_MiasmaCorruptionGaugeHUD: Updated Miasma gauge display to %f%%"), MiasmaGaugePercent * 100.0f);
}
