// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 389: Ashen Faction Merchant Shop UMG Widget

#include "AshenUserWidget_FactionMerchantShop.h"

void UAshenUserWidget_FactionMerchantShop::UpdateFactionShopDisplay(FName FactionID, int32 UnlockedItemTier)
{
	DisplayedFactionID = FactionID;
	ActiveItemTier = UnlockedItemTier;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_FactionMerchantShop: Faction Merchant Shop UI updated — '%s' (Unlocked Tier: %d)."),
		*FactionID.ToString(), UnlockedItemTier);
}
