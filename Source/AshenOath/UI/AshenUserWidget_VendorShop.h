// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenVendorMerchantSubsystem.h"
#include "AshenUserWidget_VendorShop.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVendorShopRefreshedSignature, FName, ActiveVendorID);

/**
 * UAshenUserWidget_VendorShop
 *
 * UMG backing widget for NPC merchant shop UI overlay.
 * Handles buy/sell tabs, item list display, and Ember balance updates.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_VendorShop : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void OpenVendorShop(FName VendorID, const TArray<FAshenVendorItem>& Catalog, int32 PlayerEmbers);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void CloseVendorShop();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateEmberBalance(int32 NewEmberAmount);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName CurrentVendorID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 CachedPlayerEmbers = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bShopOpen = false;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|UI|Events")
	FOnVendorShopRefreshedSignature OnShopRefreshed;
};
