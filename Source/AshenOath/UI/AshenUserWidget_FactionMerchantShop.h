// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_FactionMerchantShop.generated.h"

/**
 * UAshenUserWidget_FactionMerchantShop
 *
 * UMG backing widget rendering faction shop inventories, tier locks, and standing requirements.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_FactionMerchantShop : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateFactionShopDisplay(FName FactionID, int32 UnlockedItemTier);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedFactionID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 ActiveItemTier = 1;
};
