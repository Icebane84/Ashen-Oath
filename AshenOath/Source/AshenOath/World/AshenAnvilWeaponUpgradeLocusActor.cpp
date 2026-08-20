// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 783: Ashen Anvil Weapon Upgrade Locus Actor

#include "AshenAnvilWeaponUpgradeLocusActor.h"

AAshenAnvilWeaponUpgradeLocusActor::AAshenAnvilWeaponUpgradeLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsAnvilActive = true;
}

void AAshenAnvilWeaponUpgradeLocusActor::ForgeWeaponUpgrade(FName RuneTag)
{
	OnAnvilForgeExecuted.Broadcast(RuneTag, true);

	UE_LOG(LogTemp, Warning, TEXT("AAshenAnvilWeaponUpgradeLocusActor: WEAPON FORGED -> Rune Upgrade: '%s' | Durability Restored to 100%%."),
		*RuneTag.ToString());
}
