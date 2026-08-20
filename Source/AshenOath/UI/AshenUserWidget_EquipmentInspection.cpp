// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 598: Ashen User Widget Equipment Inspection

#include "AshenUserWidget_EquipmentInspection.h"

void UAshenUserWidget_EquipmentInspection::InspectEquipmentStoryWear(FName WeaponID, FString BattleMarkNotes, float SootDarkeningPercent)
{
	ActiveInspectedWeaponID = WeaponID;
	ActiveBattleMarkNotes = BattleMarkNotes;
	ActiveSootDarkeningPercent = FMath::Clamp(SootDarkeningPercent, 0.0f, 100.0f);

	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_EquipmentInspection: EQUIPMENT INSPECTED -> Weapon '%s' | Notes: '%s' | Soot: %.1f%%."),
		*WeaponID.ToString(), *ActiveBattleMarkNotes, ActiveSootDarkeningPercent);
}
