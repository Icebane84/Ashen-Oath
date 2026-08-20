// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 467: Ashen Armor Damage HUD UMG Widget

#include "AshenUserWidget_ArmorDamageHUD.h"

void UAshenUserWidget_ArmorDamageHUD::UpdateArmorHUDDisplay(FName LimbSlot, float RemainingIntegrity)
{
	DisplayedLimbSlot = LimbSlot;
	DisplayedIntegrity = RemainingIntegrity;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_ArmorDamageHUD: Armor Durability HUD updated — Limb '%s' (Integrity: %.1f%%)."),
		*LimbSlot.ToString(), RemainingIntegrity);
}
