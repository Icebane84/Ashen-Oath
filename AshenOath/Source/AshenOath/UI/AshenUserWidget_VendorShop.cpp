// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 195: Ashen Vendor Shop UMG Widget

#include "AshenUserWidget_VendorShop.h"

void UAshenUserWidget_VendorShop::OpenVendorShop(FName VendorID, const TArray<FAshenVendorItem>& Catalog, int32 PlayerEmbers)
{
	CurrentVendorID = VendorID;
	CachedPlayerEmbers = PlayerEmbers;
	bShopOpen = true;

	OnShopRefreshed.Broadcast(CurrentVendorID);

	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_VendorShop: SHOP OPENED for vendor '%s' — %d items in catalog, %d Embers available."),
		*VendorID.ToString(), Catalog.Num(), PlayerEmbers);
}

void UAshenUserWidget_VendorShop::CloseVendorShop()
{
	bShopOpen = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_VendorShop: SHOP CLOSED for vendor '%s'."), *CurrentVendorID.ToString());
	CurrentVendorID = NAME_None;
}

void UAshenUserWidget_VendorShop::UpdateEmberBalance(int32 NewEmberAmount)
{
	CachedPlayerEmbers = NewEmberAmount;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_VendorShop: Ember balance updated to %d."), CachedPlayerEmbers);
}
