// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_RevisitedMemoriesInspector.h"

void UAshenUserWidget_RevisitedMemoriesInspector::RefreshRevisitedMemoriesDisplay(int32 PageCount)
{
	TotalRevisitedPagesCount = PageCount;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_RevisitedMemoriesInspector: Refreshed revisited memories display (%d pages revisited)."), TotalRevisitedPagesCount);
}
