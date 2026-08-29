// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenRunicForgeNarrativeBridge.h"

UAshenRunicForgeNarrativeBridge::UAshenRunicForgeNarrativeBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenRunicForgeNarrativeBridge::FormatForgeBark(
	EOathbringerAscensionTier Tier,
	ESigilResonanceEffect Sigil) const
{
	if (Tier == EOathbringerAscensionTier::Tier5_GodslayerApex)
	{
		return FText::FromString(TEXT("[Serafina]: 'The blade resonates with the primordial White Flame. No shadow can endure this steel.'"));
	}

	if (Tier == EOathbringerAscensionTier::Tier3_SunderedSovereign)
	{
		return FText::FromString(TEXT("[Garrett]: 'All four guard sockets are cleared of slag. Time to inscribe the ancient glyphs.'"));
	}

	switch (Sigil)
	{
	case ESigilResonanceEffect::ShatteredColossus:
		return FText::FromString(TEXT("[Garrett]: 'That Colossus sigil will turn your Vom Tag overhead into an earthquake.'"));
	case ESigilResonanceEffect::ZephyrGale:
		return FText::FromString(TEXT("[Garrett]: 'The Zephyr rune channels vacuum wind on your Pflug forward thrust.'"));
	case ESigilResonanceEffect::SunkenSun:
		return FText::FromString(TEXT("[Serafina]: 'Ochs Crown Guard now shines with the radiance of the morning sun.'"));
	case ESigilResonanceEffect::GravimetricCore:
		return FText::FromString(TEXT("[Garrett]: 'A gravimetric pommel. Half-swording with this will crush full plate armor like paper.'"));
	default:
		return FText::FromString(TEXT("[Garrett]: 'Hold the tongs steady, Kaelen. Let the steel take the rune.'"));
	}
}
