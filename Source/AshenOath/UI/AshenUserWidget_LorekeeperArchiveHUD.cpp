// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_LorekeeperArchiveHUD.h"

void UAshenUserWidget_LorekeeperArchiveHUD::DisplayLorekeeperArchive(int32 MemoryCount)
{
	UnlockedMemoryCount = MemoryCount;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_LorekeeperArchiveHUD: Displaying Lorekeeper Archive (%d memories unlocked)."), UnlockedMemoryCount);
}
