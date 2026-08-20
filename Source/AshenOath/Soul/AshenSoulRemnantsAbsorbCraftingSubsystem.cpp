// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 381: Ashen Soul Remnants Absorb Crafting Subsystem

#include "AshenSoulRemnantsAbsorbCraftingSubsystem.h"

void UAshenSoulRemnantsAbsorbCraftingSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UnlockedBlueprints.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenSoulRemnantsAbsorbCraftingSubsystem: Initialized — Blueprint Archives ONLINE."));
}

bool UAshenSoulRemnantsAbsorbCraftingSubsystem::UnlockBlueprintFromAbsorbedRemnant(FName BlueprintID)
{
	if (BlueprintID.IsNone()) return false;

	UnlockedBlueprints.Add(BlueprintID);
	OnBlueprintUnlocked.Broadcast(BlueprintID, UnlockedBlueprints.Num());

	UE_LOG(LogTemp, Warning, TEXT("UAshenSoulRemnantsAbsorbCraftingSubsystem: ANCIENT BLUEPRINT UNLOCKED — '%s' (Total Unlocked: %d)."),
		*BlueprintID.ToString(), UnlockedBlueprints.Num());

	return true;
}
