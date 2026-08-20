// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_SovereignPhoenixTelemetryInspector.h"

void UAshenUserWidget_SovereignPhoenixTelemetryInspector::RefreshPhoenixTelemetryDisplay(int32 PerkCount)
{
	ActivePhoenixPerkCount = PerkCount;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_SovereignPhoenixTelemetryInspector: Refreshed Phoenix telemetry display (%d active perks)."), ActivePhoenixPerkCount);
}
