// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_GrandMasterInspector.h"

void UAshenUserWidget_GrandMasterInspector::RefreshGrandMasterInspectorDisplay(int32 BuildCount)
{
	TotalInspectedBuilds = BuildCount;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_GrandMasterInspector: Refreshed Grand Master inspector display (%d builds clean)."), TotalInspectedBuilds);
}
