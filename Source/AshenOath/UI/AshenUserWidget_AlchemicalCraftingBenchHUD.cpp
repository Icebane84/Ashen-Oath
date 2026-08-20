// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_AlchemicalCraftingBenchHUD.h"

void UAshenUserWidget_AlchemicalCraftingBenchHUD::SetCraftingBenchVisibility(bool bOpen)
{
	bIsCraftingBenchOpen = bOpen;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_AlchemicalCraftingBenchHUD: Crafting Bench Workstation: %s"),
		bIsCraftingBenchOpen ? TEXT("OPEN") : TEXT("CLOSED"));
}
