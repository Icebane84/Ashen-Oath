// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_KeystoneMemoryCrucibleHUD.h"

void UAshenUserWidget_KeystoneMemoryCrucibleHUD::DisplayMemoryCrucible(FName MemoryID)
{
	ActiveMemoryID = MemoryID;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_KeystoneMemoryCrucibleHUD: Displaying Keystone Memory Crucible for %s."),
		*ActiveMemoryID.ToString());
}
