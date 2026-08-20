// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 216: Ashen Soul Perk Node Component

#include "AshenSoulPerkNodeComponent.h"

UAshenSoulPerkNodeComponent::UAshenSoulPerkNodeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PerkID = FName("Perk_Default");
	AshUnlockCost = 150.0f;
	bIsUnlocked = false;
}

void UAshenSoulPerkNodeComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenSoulPerkNodeComponent::UnlockPerk(float PlayerAshAmount, bool bPrerequisiteMet)
{
	if (bIsUnlocked) return true; // Already unlocked

	if (!bPrerequisiteMet)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenSoulPerkNodeComponent: Cannot unlock '%s' — prerequisite node not unlocked."), *PerkID.ToString());
		return false;
	}

	if (PlayerAshAmount < AshUnlockCost)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenSoulPerkNodeComponent: Cannot unlock '%s' — insufficient Ash (%.0f / %.0f required)."),
			*PerkID.ToString(), PlayerAshAmount, AshUnlockCost);
		return false;
	}

	bIsUnlocked = true;
	OnPerkUnlocked.Broadcast(PerkID, AshUnlockCost);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSoulPerkNodeComponent: PERK UNLOCKED — '%s' for %.0f Ash."), *PerkID.ToString(), AshUnlockCost);
	return true;
}
