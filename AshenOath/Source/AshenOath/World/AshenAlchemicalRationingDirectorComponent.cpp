// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenAlchemicalRationingDirectorComponent.h"

UAshenAlchemicalRationingDirectorComponent::UAshenAlchemicalRationingDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenAlchemicalRationingDirectorComponent::ValidateIngredientsForRecipe(
	ECampfireRecipeType Recipe,
	int32 MeatCount,
	int32 HerbCount,
	int32 SaltCount) const
{
	switch (Recipe)
	{
	case ECampfireRecipeType::SentinelsIronBroth:
		return MeatCount >= 1 && SaltCount >= 1;
	case ECampfireRecipeType::WhiteFlameHerbalTisane:
		return HerbCount >= 2;
	case ECampfireRecipeType::GloomwoodVenisonStew:
		return MeatCount >= 2 && HerbCount >= 1;
	case ECampfireRecipeType::GrandZenithSoulGoulash:
		return MeatCount >= 2 && HerbCount >= 2 && SaltCount >= 1;
	case ECampfireRecipeType::None:
	default:
		return false;
	}
}
