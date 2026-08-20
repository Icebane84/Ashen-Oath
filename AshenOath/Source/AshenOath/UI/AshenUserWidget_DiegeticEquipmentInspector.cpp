// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_DiegeticEquipmentInspector.h"

void UAshenUserWidget_DiegeticEquipmentInspector::InspectItem(FName ItemID, FText ItemName, FText InspectionNotes)
{
	ActiveItemID = ItemID;
	ActiveItemName = ItemName;
	ActiveInspectionNotes = InspectionNotes;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_DiegeticEquipmentInspector: Inspecting item '%s'"), *ActiveItemName.ToString());
}
