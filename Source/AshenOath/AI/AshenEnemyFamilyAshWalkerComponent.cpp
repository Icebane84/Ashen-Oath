// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 483: Ashen Enemy Family Ash Walker Component

#include "AshenEnemyFamilyAshWalkerComponent.h"

UAshenEnemyFamilyAshWalkerComponent::UAshenEnemyFamilyAshWalkerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsHyperArmorActive = false;
	DamageMitigationPercent = 50.0f;
}

void UAshenEnemyFamilyAshWalkerComponent::SetHyperArmorState(bool bActive)
{
	bIsHyperArmorActive = bActive;
	OnHyperArmorStateChanged.Broadcast(bActive, DamageMitigationPercent);

	UE_LOG(LogTemp, Warning, TEXT("UAshenEnemyFamilyAshWalkerComponent: ASH WALKER HYPER ARMOR STATE -> %s (Mitigation: %.0f%%)."),
		bActive ? TEXT("ACTIVE") : TEXT("INACTIVE"), DamageMitigationPercent);
}
