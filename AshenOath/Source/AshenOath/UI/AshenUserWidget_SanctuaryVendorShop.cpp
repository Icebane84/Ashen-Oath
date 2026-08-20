// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 414: Ashen Sanctuary Vendor Shop UMG Widget

#include "AshenUserWidget_SanctuaryVendorShop.h"

void UAshenUserWidget_SanctuaryVendorShop::UpdateSanctuaryVendorShopDisplay(FName VendorID, float DiscountMultiplier)
{
	DisplayedVendorID = VendorID;
	DisplayedDiscountMultiplier = DiscountMultiplier;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_SanctuaryVendorShop: Sanctuary Vendor Shop UI updated — '%s' (Discount Multiplier: %.2fx)."),
		*VendorID.ToString(), DiscountMultiplier);
}
