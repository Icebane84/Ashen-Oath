// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenAlchemicalCraftingPostProcessAdapter.h"

UAshenAlchemicalCraftingPostProcessAdapter::UAshenAlchemicalCraftingPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenAlchemicalCraftingPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenAlchemicalCraftingPostProcessAdapter::ApplyCampfireCraftingPostProcess(bool bIsWorkstationOpen, float CampfireIntensity)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenAlchemicalCraftingPostProcessAdapter: Workstation Post-Process -> Open: %s, Fire Intensity: %.2f"),
		bIsWorkstationOpen ? TEXT("TRUE") : TEXT("FALSE"), CampfireIntensity);
}
