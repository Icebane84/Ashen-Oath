// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_DiegeticEquipmentInspector.generated.h"

UCLASS(Abstract)
class ASHENOATH_API UAshenUserWidget_DiegeticEquipmentInspector : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void InspectItem(FName ItemID, FText ItemName, FText InspectionNotes);

	UFUNCTION(BlueprintPure, Category = "Ashen Oath | UI")
	FText GetActiveItemName() const { return ActiveItemName; }

private:
	FName ActiveItemID;
	FText ActiveItemName;
	FText ActiveInspectionNotes;
};
