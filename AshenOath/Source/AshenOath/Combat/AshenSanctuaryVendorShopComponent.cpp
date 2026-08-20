// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 281: Ashen Sanctuary Vendor Shop Component

#include "AshenSanctuaryVendorShopComponent.h"
#include "AshenOath_CurrencyComponent.h"

UAshenSanctuaryVendorShopComponent::UAshenSanctuaryVendorShopComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSanctuaryVendorShopComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenSanctuaryVendorShopComponent::PurchaseItem(AActor* BuyerActor, FName ItemID, float ItemCost)
{
	if (!BuyerActor || ItemID.IsNone() || ItemCost <= 0.0f) return false;

	UAshenOath_CurrencyComponent* CurrencyComp = BuyerActor->FindComponentByClass<UAshenOath_CurrencyComponent>();
	if (!CurrencyComp) return false;

	bool bDeducted = CurrencyComp->DeductEmbers(ItemCost);
	OnVendorPurchase.Broadcast(ItemID, ItemCost, bDeducted);

	if (bDeducted)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenSanctuaryVendorShopComponent: PURCHASE SUCCESS — '%s' bought for %.0f Embers by '%s'."),
			*ItemID.ToString(), ItemCost, *BuyerActor->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenSanctuaryVendorShopComponent: PURCHASE FAILED — Insufficient Embers for '%s' (Cost: %.0f)."),
			*ItemID.ToString(), ItemCost);
	}

	return bDeducted;
}
