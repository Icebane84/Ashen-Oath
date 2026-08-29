// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenSanctuarySurvivalNarrativeBridge.h"

UAshenSanctuarySurvivalNarrativeBridge::UAshenSanctuarySurvivalNarrativeBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenSanctuarySurvivalNarrativeBridge::FormatSurvivalBark(
	EThermalShelterTier Tier,
	ECookedMealBuffType Meal) const
{
	if (Tier == EThermalShelterTier::SanctuaryHearthRadius)
	{
		return FText::FromString(TEXT("[Serafina]: 'The hearth burns once more. May the White Flame keep the shadows at bay.'"));
	}

	if (Tier == EThermalShelterTier::NaturalCavern)
	{
		return FText::FromString(TEXT("[Garrett]: 'Good thinking stepping inside this cavern. Set up the campfire; boiling will take half the time.'"));
	}

	switch (Meal)
	{
	case ECookedMealBuffType::GlacialHeartStew:
		return FText::FromString(TEXT("[Garrett]: 'That troll fat stew should keep your blood boiling through the whiteout.'"));
	case ECookedMealBuffType::VitriolPurgeBroth:
		return FText::FromString(TEXT("[Garrett]: 'Vitriol broth coats the throat. The acid rain won't burn your skin now.'"));
	case ECookedMealBuffType::CinderAshCake:
		return FText::FromString(TEXT("[Serafina]: 'Ember grains steel the lungs against the volcanic choking fog.'"));
	default:
		return FText::FromString(TEXT("[Garrett]: 'Keep an eye on the frost on your gauntlets, Kaelen.'"));
	}
}
