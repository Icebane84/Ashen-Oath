// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOath_InventoryComponent.h"
#include "AshenQuickUseBeltComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnQuickBeltSlotChangedSignature, int32, ActiveSlotIndex, FAshenItemData, ItemData);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnQuickBeltItemUsedSignature, FName, ItemID, int32, RemainingQuantity);

/**
 * UAshenQuickUseBeltComponent
 *
 * Manages a 4-slot consumable item quick-belt.
 * Allows cycling active item slots and consuming items with cooldown tracking.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenQuickUseBeltComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenQuickUseBeltComponent();

protected:
	virtual void BeginPlay() override;

public:
	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|QuickBelt")
	void AssignItemToSlot(int32 SlotIndex, FAshenItemData ItemData);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|QuickBelt")
	void CycleSlot(bool bNextSlot);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|QuickBelt")
	bool UseActiveItem();

	UFUNCTION(BlueprintPure, Category = "AshenOath|QuickBelt")
	int32 GetActiveSlotIndex() const { return ActiveSlotIndex; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|QuickBelt")
	FAshenItemData GetActiveItemData() const;

	UFUNCTION(BlueprintPure, Category = "AshenOath|QuickBelt")
	bool IsOnUseCooldown() const { return bOnCooldown; }

	// --- Configuration ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|QuickBelt")
	int32 MaxBeltSlots = 4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|QuickBelt")
	float UseCooldownDuration = 1.0f;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|QuickBelt|Events")
	FOnQuickBeltSlotChangedSignature OnQuickSlotChanged;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|QuickBelt|Events")
	FOnQuickBeltItemUsedSignature OnQuickItemUsed;

private:
	int32 ActiveSlotIndex = 0;
	TArray<FAshenItemData> BeltSlots;
	bool bOnCooldown = false;

	FTimerHandle CooldownTimerHandle;
	void ResetCooldown();
};
