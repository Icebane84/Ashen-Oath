// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_JournalSoulConstellationNodeMap.h"

void UAshenUserWidget_JournalSoulConstellationNodeMap::OnSoulStateInvalidated(const FSoulStateVector& StateVector)
{
	UnlockedConstellationNodeCount = 1 + FMath::FloorToInt(StateVector.Resolve * 6.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_JournalSoulConstellationNodeMap: Unlocked constellation nodes updated to %d"), UnlockedConstellationNodeCount);
}
