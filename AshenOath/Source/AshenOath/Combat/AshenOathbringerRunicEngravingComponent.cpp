// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 781: Ashen Oathbringer Runic Engraving Component

#include "AshenOathbringerRunicEngravingComponent.h"

UAshenOathbringerRunicEngravingComponent::UAshenOathbringerRunicEngravingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveEngravedRune = FName(TEXT("Rune.WhiteFlameSun"));
}

void UAshenOathbringerRunicEngravingComponent::EngraveHolyRune(FName RuneTag, float HolyDamageBonus)
{
	ActiveEngravedRune = RuneTag;
	OnRuneEngraved.Broadcast(ActiveEngravedRune, HolyDamageBonus);

	UE_LOG(LogTemp, Warning, TEXT("UAshenOathbringerRunicEngravingComponent: HOLY RUNE ENGRAVED -> Rune: '%s' | Bonus Holy Damage: +%.1f HP."),
		*ActiveEngravedRune.ToString(), HolyDamageBonus);
}
