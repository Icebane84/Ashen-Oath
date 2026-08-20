// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_EquipmentInspectionHUD.h"

void UAshenUserWidget_EquipmentInspectionHUD::InspectWeapon(FName ItemName, int32 RuneCount)
{
	InspectedItemName = ItemName;
	InscribedRuneCount = RuneCount;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_EquipmentInspectionHUD: Inspecting %s (%d runes inscribed)."),
		*InspectedItemName.ToString(), InscribedRuneCount);
}
