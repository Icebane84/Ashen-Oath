// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 192: Ashen Vendor Merchant Subsystem

#include "AshenVendorMerchantSubsystem.h"
#include "AshenOath_InventoryComponent.h"
#include "AshenOath_CurrencyComponent.h"
#include "GameFramework/Pawn.h"

void UAshenVendorMerchantSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	Vendors.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenVendorMerchantSubsystem: Initialized — Merchant Network online."));
}

void UAshenVendorMerchantSubsystem::RegisterVendor(FName VendorID)
{
	if (VendorID.IsNone() || Vendors.Contains(VendorID)) return;

	FVendorCatalog Catalog;
	Vendors.Add(VendorID, Catalog);
	UE_LOG(LogTemp, Log, TEXT("UAshenVendorMerchantSubsystem: Registered vendor '%s'."), *VendorID.ToString());
}

void UAshenVendorMerchantSubsystem::AddVendorItem(FName VendorID, FAshenItemData ItemData, int32 PriceInEmbers, int32 Stock)
{
	FVendorCatalog* Catalog = Vendors.Find(VendorID);
	if (!Catalog) return;

	FAshenVendorItem Item;
	Item.ItemData = ItemData;
	Item.PriceInEmbers = PriceInEmbers;
	Item.StockRemaining = Stock;

	Catalog->Items.Add(Item);
	UE_LOG(LogTemp, Log, TEXT("UAshenVendorMerchantSubsystem: Added item '%s' (%d Embers, %d stock) to vendor '%s'."),
		*ItemData.ItemName, PriceInEmbers, Stock, *VendorID.ToString());
}

bool UAshenVendorMerchantSubsystem::BuyItem(APawn* BuyerPawn, FName VendorID, FName ItemID)
{
	if (!BuyerPawn) return false;

	FVendorCatalog* Catalog = Vendors.Find(VendorID);
	if (!Catalog) return false;

	for (FAshenVendorItem& VItem : Catalog->Items)
	{
		if (VItem.ItemData.ItemID == ItemID)
		{
			if (VItem.StockRemaining <= 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("UAshenVendorMerchantSubsystem: Item '%s' is OUT OF STOCK at vendor '%s'."),
					*ItemID.ToString(), *VendorID.ToString());
				return false;
			}

			// Check currency
			UAshenOath_CurrencyComponent* Currency = BuyerPawn->FindComponentByClass<UAshenOath_CurrencyComponent>();
			if (Currency && Currency->GetEmbers() < (float)VItem.PriceInEmbers)
			{
				UE_LOG(LogTemp, Warning, TEXT("UAshenVendorMerchantSubsystem: Buyer '%s' has insufficient Embers (%d required)."),
					*BuyerPawn->GetName(), VItem.PriceInEmbers);
				return false;
			}

			// Deduct currency & add item
			if (Currency)
			{
				Currency->DeductEmbers((float)VItem.PriceInEmbers);
			}

			UAshenOath_InventoryComponent* Inventory = BuyerPawn->FindComponentByClass<UAshenOath_InventoryComponent>();
			if (Inventory)
			{
				FAshenItemData PurchasedItem = VItem.ItemData;
				PurchasedItem.Quantity = 1;
				Inventory->AddItem(PurchasedItem);
			}

			VItem.StockRemaining--;
			OnTransactionCompleted.Broadcast(VendorID, ItemID, true);

			UE_LOG(LogTemp, Warning, TEXT("UAshenVendorMerchantSubsystem: BOUGHT item '%s' from '%s' for %d Embers (%d stock left)."),
				*ItemID.ToString(), *VendorID.ToString(), VItem.PriceInEmbers, VItem.StockRemaining);

			return true;
		}
	}

	return false;
}

bool UAshenVendorMerchantSubsystem::SellItem(APawn* SellerPawn, FName VendorID, FName ItemID, int32 SellPriceEmbers)
{
	if (!SellerPawn) return false;

	UAshenOath_InventoryComponent* Inventory = SellerPawn->FindComponentByClass<UAshenOath_InventoryComponent>();
	if (!Inventory) return false;

	// Award Embers
	UAshenOath_CurrencyComponent* Currency = SellerPawn->FindComponentByClass<UAshenOath_CurrencyComponent>();
	if (Currency)
	{
		Currency->AddEmbers((float)SellPriceEmbers);
	}

	OnTransactionCompleted.Broadcast(VendorID, ItemID, false);

	UE_LOG(LogTemp, Warning, TEXT("UAshenVendorMerchantSubsystem: SOLD item '%s' to '%s' for %d Embers."),
		*ItemID.ToString(), *VendorID.ToString(), SellPriceEmbers);

	return true;
}

TArray<FAshenVendorItem> UAshenVendorMerchantSubsystem::GetVendorCatalog(FName VendorID) const
{
	const FVendorCatalog* Catalog = Vendors.Find(VendorID);
	return Catalog ? Catalog->Items : TArray<FAshenVendorItem>();
}
