// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_TriggerFrictionTelemetryHUD.h"

void UAshenUserWidget_TriggerFrictionTelemetryHUD::UpdateTriggerTelemetry(float InL2, float InR2)
{
	L2TravelPercentage = InL2 * 100.0f;
	R2TravelPercentage = InR2 * 100.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_TriggerFrictionTelemetryHUD: Trigger Telemetry -> L2: %.1f%%, R2: %.1f%%"),
		L2TravelPercentage, R2TravelPercentage);
}
