// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_DualityEngineInspector.h"

void UAshenUserWidget_DualityEngineInspector::DisplayDualityShaderTelemetry(float CorruptionScalar, float Soot, float SeamGrime)
{
	DisplayedCorruptionScalar = CorruptionScalar;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_DualityEngineInspector: Displayed Duality shader telemetry (Corruption: %f, Soot: %f, Seam Grime: %f)"), DisplayedCorruptionScalar, Soot, SeamGrime);
}
