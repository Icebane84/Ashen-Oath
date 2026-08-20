// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenOath_InventoryComponent.h"
#include "AshenVendorMerchantSubsystem.generated.h"

USTRUCT(BlueprintType)
struct FAshenVendorItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Vendor")
	FAshenItemData ItemData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Vendor")
	int32 PriceInEmbers = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Vendor")
	int32 StockRemaining = 10;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnVendorTransactionSignature, FName, VendorID, FName, ItemID, bool, bIsBuy);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVendorRestockedSignature, FName, VendorID);

/**
 * UAshenVendorMerchantSubsystem
 *
 * World Subsystem managing NPC merchant catalogs, stock tracking,
 * and buy/sell transactions using player Ember currency.
 */
UCLASS()
class ASHENOATH_API UAshenVendorMerchantSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Vendor")
	void RegisterVendor(FName VendorID);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Vendor")
	void AddVendorItem(FName VendorID, FAshenItemData ItemData, int32 PriceInEmbers, int32 Stock);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Vendor")
	bool BuyItem(APawn* BuyerPawn, FName VendorID, FName ItemID);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Vendor")
	bool SellItem(APawn* SellerPawn, FName VendorID, FName ItemID, int32 SellPriceEmbers);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Vendor")
	TArray<FAshenVendorItem> GetVendorCatalog(FName VendorID) const;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Vendor|Events")
	FOnVendorTransactionSignature OnTransactionCompleted;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Vendor|Events")
	FOnVendorRestockedSignature OnVendorRestocked;

private:
	struct FVendorCatalog
	{
		TArray<FAshenVendorItem> Items;
	};

	TMap<FName, FVendorCatalog> Vendors;
};
