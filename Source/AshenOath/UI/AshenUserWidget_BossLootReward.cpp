// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 254: Ashen Boss Loot Reward UMG Widget

#include "AshenUserWidget_BossLootReward.h"

void UAshenUserWidget_BossLootReward::DisplayRewardOverlay(float EmbersGained, FName ItemRewardID, const FText& ItemNameText)
{
	DisplayedEmbers = EmbersGained;
	DisplayedItemID = ItemRewardID;
	DisplayedItemName = ItemNameText;
	bRewardActive = true;

	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_BossLootReward: VICTORY REWARD DISPLAYED — %.0f Embers, Item: '%s' ('%s')."),
		EmbersGained, *ItemRewardID.ToString(), *ItemNameText.ToString());
}

void UAshenUserWidget_BossLootReward::DismissRewardOverlay()
{
	bRewardActive = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_BossLootReward: Victory reward screen dismissed."));
}
