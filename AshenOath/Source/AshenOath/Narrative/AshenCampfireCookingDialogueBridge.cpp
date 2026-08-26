// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenCampfireCookingDialogueBridge.h"

UAshenCampfireCookingDialogueBridge::UAshenCampfireCookingDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenCampfireCookingDialogueBridge::FormatCookingBark(
	ECampfireRecipeType Recipe,
	ECookingPotState PotState) const
{
	if (PotState == ECookingPotState::MealReadyServed)
	{
		switch (Recipe)
		{
		case ECampfireRecipeType::SentinelsIronBroth:
			return FText::FromString(TEXT("[Garrett]: 'Iron broth is ready. Thick enough to coat your ribs against cold steel.'"));
		case ECampfireRecipeType::WhiteFlameHerbalTisane:
			return FText::FromString(TEXT("[Serafina]: 'The tisane has steeped. Let the warmth quiet the noise in your chest.'"));
		case ECampfireRecipeType::GloomwoodVenisonStew:
			return FText::FromString(TEXT("[Kaelen]: 'Venison's cooked. Eat while the fat is hot—tomorrow the road gets steep.'"));
		case ECampfireRecipeType::GrandZenithSoulGoulash:
			return FText::FromString(TEXT("[Garrett]: 'Now that... that smells like the grand zenith feasts before the sunder.'"));
		case ECampfireRecipeType::None:
		default:
			break;
		}
	}

	return FText::FromString(TEXT("[Garrett]: 'Keep the embers stoked. Slow heat makes the marrow render.'"));
}
