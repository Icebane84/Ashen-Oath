// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenOath_InventoryComponent.h"
#include "AshenUserWidget_QuickBelt.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuickBeltWidgetRefreshedSignature, int32, ActiveSlot);

/**
 * UAshenUserWidget_QuickBelt
 *
 * UMG backing widget for the 4-slot consumable quick-belt interface.
 * Updates slot item displays and highlights the active selection slot.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_QuickBelt : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void RefreshSlotDisplay(int32 SlotIndex, FAshenItemData ItemData);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void SetActiveSlotHighlight(int32 SlotIndex);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 CurrentActiveSlot = 0;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|UI|Events")
	FOnQuickBeltWidgetRefreshedSignature OnQuickBeltRefreshed;
};
