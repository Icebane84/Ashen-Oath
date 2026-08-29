// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenAlchemicalSlagNarrativeBridge.h"

UAshenAlchemicalSlagNarrativeBridge::UAshenAlchemicalSlagNarrativeBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenAlchemicalSlagNarrativeBridge::FormatReactionBark(
	EThermalReactionType Reaction,
	EAlchemicalBladeCoating Coating) const
{
	switch (Reaction)
	{
	case EThermalReactionType::ConflagrationDeflagration:
		return FText::FromString(TEXT("[Garrett]: 'Boom! That naphtha cooked them to a crisp!'"));

	case EThermalReactionType::ThermalShockShatter:
		return FText::FromString(TEXT("[Garrett]: 'Thermal shock! Their armor just cracked like eggshells!'"));

	case EThermalReactionType::GalvanicShockBurst:
		return FText::FromString(TEXT("[Garrett]: 'The copper drew the lightning right down on their heads!'"));

	case EThermalReactionType::AcidicVaporCloud:
		return FText::FromString(TEXT("[Garrett]: 'Acid vapor! Stay clear of the yellow smoke!'"));

	case EThermalReactionType::None:
	default:
		switch (Coating)
		{
		case EAlchemicalBladeCoating::PyrophoricNaphtha:
			return FText::FromString(TEXT("[Garrett]: 'Naphtha oil applied! Next heavy strike will ignite!'"));
		case EAlchemicalBladeCoating::GlacialFrostResin:
			return FText::FromString(TEXT("[Garrett]: 'Frost resin spread. Slow them down, Kaelen!'"));
		case EAlchemicalBladeCoating::VitriolAcid:
			return FText::FromString(TEXT("[Garrett]: 'Vitriol acid active. Carve straight through their plates!'"));
		case EAlchemicalBladeCoating::ConductiveCopperSalve:
			return FText::FromString(TEXT("[Garrett]: 'Copper salve primed. Call the storm down!'"));
		default:
			return FText::FromString(TEXT("[Garrett]: 'Keep the blade ready, Kaelen.'"));
		}
	}
}
