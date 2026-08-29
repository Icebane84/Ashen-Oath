// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenRunicSeamGlyphDirectorComponent.h"

UAshenRunicSeamGlyphDirectorComponent::UAshenRunicSeamGlyphDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FLinearColor UAshenRunicSeamGlyphDirectorComponent::EvaluateGlyphColor(
	ESigilResonanceEffect Sigil) const
{
	switch (Sigil)
	{
	case ESigilResonanceEffect::ShatteredColossus:
		return FLinearColor(0.95f, 0.25f, 0.05f, 1.0f); // Fiery Ember Ochre (Vom Tag)
	case ESigilResonanceEffect::ZephyrGale:
		return FLinearColor(0.85f, 0.95f, 1.0f, 1.0f);  // Luminous White Flame Wind (Pflug)
	case ESigilResonanceEffect::SunkenSun:
		return FLinearColor(1.0f, 0.85f, 0.15f, 1.0f);  // Radiant Crown Gold (Ochs)
	case ESigilResonanceEffect::GravimetricCore:
		return FLinearColor(0.55f, 0.15f, 0.85f, 1.0f); // Deep Umbral Violet (Mordhau)
	case ESigilResonanceEffect::None:
	default:
		return FLinearColor(0.05f, 0.05f, 0.05f, 0.0f); // Dark Nightsteel
	}
}
