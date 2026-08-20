// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOath_InventoryComponent.generated.h"

USTRUCT(BlueprintType)
struct FAshenItemData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	FName ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 Quantity;

	FAshenItemData()
		: ItemID(NAME_None)
		, ItemName(TEXT(""))
		, Quantity(0)
	{}

	FAshenItemData(FName InItemID, FString InItemName, int32 InQuantity)
		: ItemID(InItemID)
		, ItemName(InItemName)
		, Quantity(InQuantity)
	{}
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdatedSignature);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOath_InventoryComponent();

protected:
	virtual void BeginPlay() override;

public:
	/** Add item to inventory */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Inventory")
	void AddItem(const FAshenItemData& Item);

	/** Remove quantity of an item from inventory. Returns true if successful. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Inventory")
	bool RemoveItem(FName ItemID, int32 QuantityToRemove);

	/** Get read-only copy of inventory items */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Inventory")
	TArray<FAshenItemData> GetInventoryItems() const { return InventoryItems; }

	/** Load inventory states dynamically from save game */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Inventory")
	void LoadInventoryState(const TArray<FAshenItemData>& InItems);

public:
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Inventory|Events")
	FOnInventoryUpdatedSignature OnInventoryUpdated;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	TArray<FAshenItemData> InventoryItems;
};
