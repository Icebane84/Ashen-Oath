// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_BossLootReward.generated.h"

/**
 * UAshenUserWidget_BossLootReward
 *
 * UMG backing widget rendering the victory reward screen overlay (Embers Gained, Rare Equipment Items, Experience).
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_BossLootReward : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void DisplayRewardOverlay(float EmbersGained, FName ItemRewardID, const FText& ItemNameText);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void DismissRewardOverlay();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedEmbers = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedItemID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FText DisplayedItemName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bRewardActive = false;
};
