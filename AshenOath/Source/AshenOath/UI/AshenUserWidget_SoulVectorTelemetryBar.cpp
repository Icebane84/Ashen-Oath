// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_SoulVectorTelemetryBar.h"

void UAshenUserWidget_SoulVectorTelemetryBar::UpdateTelemetryDisplay(const FSoulStateVector& StateVector)
{
	CachedIsolation = StateVector.Isolation;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_SoulVectorTelemetryBar: Telemetry bar display refreshed — Isolation: %.2f, Resolve: %.2f, Corruption: %.2f"),
		StateVector.Isolation, StateVector.Resolve, StateVector.Corruption);
}
