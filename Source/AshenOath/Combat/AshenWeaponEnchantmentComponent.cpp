// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 568: Ashen Weapon Enchantment Component

#include "AshenWeaponEnchantmentComponent.h"

UAshenWeaponEnchantmentComponent::UAshenWeaponEnchantmentComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveBonusDamage = 0.0f;
}

void UAshenWeaponEnchantmentComponent::ApplyEnchantment(FName ElementTag, float BonusDamage)
{
	ActiveElementTag = ElementTag;
	ActiveBonusDamage = BonusDamage;

	OnWeaponEnchanted.Broadcast(ElementTag, BonusDamage);

	UE_LOG(LogTemp, Warning, TEXT("UAshenWeaponEnchantmentComponent: WEAPON ENCHANTED -> Element: '%s' | Bonus Damage: +%.1f."),
		*ElementTag.ToString(), BonusDamage);
}
