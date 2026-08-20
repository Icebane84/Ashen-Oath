// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenEquipmentInspectionViewModel.h"

UAshenEquipmentInspectionViewModel::UAshenEquipmentInspectionViewModel()
{
}

void UAshenEquipmentInspectionViewModel::InspectEquipmentItem(FName ItemName)
{
	InspectedItemName = ItemName;
	UE_LOG(LogTemp, Log, TEXT("UAshenEquipmentInspectionViewModel: Inspecting 3D physical equipment item %s"), *InspectedItemName.ToString());
}
