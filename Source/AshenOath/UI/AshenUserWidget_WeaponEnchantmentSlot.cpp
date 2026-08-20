// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 224: Ashen Weapon Enchantment Slot UMG Widget

#include "AshenUserWidget_WeaponEnchantmentSlot.h"

void UAshenUserWidget_WeaponEnchantmentSlot::UpdateInfusionSlot(EAshenElementInfusion Infusion, float RemainingDuration, float BonusDamage)
{
	CurrentInfusion = Infusion;
	CurrentRemainingDuration = FMath::Max(0.0f, RemainingDuration);
	CurrentBonusDamage = BonusDamage;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_WeaponEnchantmentSlot: Infusion slot updated to Element %d — %.1fs remaining (+%.0f dmg)."),
		(int32)CurrentInfusion, CurrentRemainingDuration, CurrentBonusDamage);
}
