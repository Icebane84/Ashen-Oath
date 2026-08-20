// AshenUpgradeStationActor.cpp
// Copyright Ashen Oath. All rights reserved.

#include "AshenUpgradeStationActor.h"
#include "AshenOath_CurrencyComponent.h"

AAshenUpgradeStationActor::AAshenUpgradeStationActor()
{
	PrimaryActorTick.bCanEverTick = false;
	InteractionText = TEXT("Access Ash Upgrade Crucible");

	// Pre-populate default Ash upgrades so shop is ready out-of-the-box
	FAshenUpgradeRecord Upgrade1;
	Upgrade1.UpgradeID = "UG_SanityAnchor";
	Upgrade1.UpgradeName = FText::FromString("Sanity Anchor");
	Upgrade1.Description = FText::FromString("Reduces environmental sanity drain in Null Zones by 20%.");
	Upgrade1.AshCost = 100.0f;
	Upgrades.Add(Upgrade1);

	FAshenUpgradeRecord Upgrade2;
	Upgrade2.UpgradeID = "UG_ResonantParry";
	Upgrade2.UpgradeName = FText::FromString("Resonant Parry");
	Upgrade2.Description = FText::FromString("Successful parries immediately restore 5 Stamina.");
	Upgrade2.AshCost = 150.0f;
	Upgrades.Add(Upgrade2);

	FAshenUpgradeRecord Upgrade3;
	Upgrade3.UpgradeID = "UG_OathbringerEdge";
	Upgrade3.UpgradeName = FText::FromString("Oathbringer Edge");
	Upgrade3.Description = FText::FromString("Increases Greatsword base physical damage by +10%.");
	Upgrade3.AshCost = 200.0f;
	Upgrades.Add(Upgrade3);
}


void AAshenUpgradeStationActor::Interact_Implementation(APawn* Player)
{
	UE_LOG(LogTemp, Log, TEXT("AAshenUpgradeStationActor: Interacted by %s. UI opened."), Player ? *Player->GetName() : TEXT("nullptr"));
}


bool AAshenUpgradeStationActor::PurchaseUpgrade(AActor* Interactor, FName UpgradeID)
{
	if (!Interactor) return false;

	FAshenUpgradeRecord* Found = Upgrades.FindByPredicate([UpgradeID](const FAshenUpgradeRecord& Rec) { return Rec.UpgradeID == UpgradeID; });
	if (!Found || Found->bPurchased)
	{
		return false;
	}

	if (UAshenOath_CurrencyComponent* Currency = Interactor->FindComponentByClass<UAshenOath_CurrencyComponent>())
	{
		if (Currency->DeductAsh(Found->AshCost))
		{
			Found->bPurchased = true;
			UE_LOG(LogTemp, Log, TEXT("PurchaseUpgrade: Successfully unlocked '%s' for %.1f Ash."), *UpgradeID.ToString(), Found->AshCost);
			OnUpgradePurchased.Broadcast(*Found);
			return true;
		}
	}

	return false;
}
