// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOath_QuickbarComponent.generated.h"

USTRUCT(BlueprintType)
struct ASHENOATH_API FQuickbarItemSlot
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Quickbar")
	FName ItemId = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Quickbar")
	FText ItemDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Quickbar")
	int32 Quantity = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Quickbar")
	int32 MaxCapacity = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Quickbar")
	float CooldownDuration = 2.0f;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnQuickSlotChangedSignature, int32, SlotIndex, const FQuickbarItemSlot&, SlotData);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnQuickItemUsedSignature, int32, SlotIndex, FName, ItemId);

/**
 * UAshenOath_QuickbarComponent
 *
 * 4-slot consumable quickbar component (Smoke Balm, Ghostbloom Tripwire, Ember Vial, Transference Catalyst).
 * Manages item equipping, quantity tracking, cooldowns, and consumption events.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_QuickbarComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOath_QuickbarComponent();

protected:
	virtual void BeginPlay() override;

public:
	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Quickbar")
	bool EquipItemToSlot(int32 SlotIndex, FName ItemId, FText DisplayName, int32 Quantity, float Cooldown = 2.0f);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Quickbar")
	bool UseQuickSlot(int32 SlotIndex);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Quickbar")
	bool GetSlotData(int32 SlotIndex, FQuickbarItemSlot& OutSlotData) const;

	UFUNCTION(BlueprintPure, Category = "AshenOath|Quickbar")
	bool IsSlotOnCooldown(int32 SlotIndex) const;

	// --- Quickbar Slots ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Quickbar")
	TArray<FQuickbarItemSlot> QuickSlots;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Quickbar|Events")
	FOnQuickSlotChangedSignature OnQuickSlotChanged;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Quickbar|Events")
	FOnQuickItemUsedSignature OnQuickItemUsed;

private:
	UPROPERTY(Transient)
	TArray<float> CooldownTimers;
};
