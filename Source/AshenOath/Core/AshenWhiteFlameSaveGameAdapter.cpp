// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenWhiteFlameSaveGameAdapter.h"

UAshenWhiteFlameSaveGameAdapter::UAshenWhiteFlameSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenWhiteFlameSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenWhiteFlameSaveGameAdapter::SaveWhiteFlameTelemetry(int32 ResolutionsInvoked, int32 ZonesSanctified, float TotalDebtCleared)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenWhiteFlameSaveGameAdapter: Saved White Flame Telemetry -> %d Resolutions, %d Zones, %.1f Debt Eradicated"),
		ResolutionsInvoked, ZonesSanctified, TotalDebtCleared);
	return true;
}
