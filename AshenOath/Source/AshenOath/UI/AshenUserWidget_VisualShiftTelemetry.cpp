// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_VisualShiftTelemetry.h"

void UAshenUserWidget_VisualShiftTelemetry::RefreshTelemetry(float Emissive, float BlendRatio)
{
	EmissiveIntensity = Emissive;
	DualityBlendRatio = BlendRatio;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_VisualShiftTelemetry: Telemetry refreshed — Emissive: %.2f | Duality Blend: %.2f"), EmissiveIntensity, DualityBlendRatio);
}
