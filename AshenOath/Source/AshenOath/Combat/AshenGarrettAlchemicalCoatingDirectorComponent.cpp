// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenGarrettAlchemicalCoatingDirectorComponent.h"

UAshenGarrettAlchemicalCoatingDirectorComponent::UAshenGarrettAlchemicalCoatingDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	FlaskInventory.Add(EAlchemicalBladeCoating::PyrophoricNaphtha, 3);
	FlaskInventory.Add(EAlchemicalBladeCoating::GlacialFrostResin, 3);
	FlaskInventory.Add(EAlchemicalBladeCoating::VitriolAcid, 3);
	FlaskInventory.Add(EAlchemicalBladeCoating::ConductiveCopperSalve, 3);
}

int32 UAshenGarrettAlchemicalCoatingDirectorComponent::GetFlaskCount(
	EAlchemicalBladeCoating Coating) const
{
	if (const int32* Count = FlaskInventory.Find(Coating))
	{
		return *Count;
	}
	return 0;
}

bool UAshenGarrettAlchemicalCoatingDirectorComponent::ConsumeFlask(
	EAlchemicalBladeCoating Coating)
{
	if (int32* Count = FlaskInventory.Find(Coating))
	{
		if (*Count > 0)
		{
			(*Count)--;
			return true;
		}
	}
	return false;
}

void UAshenGarrettAlchemicalCoatingDirectorComponent::AddBrewedFlasks(
	EAlchemicalBladeCoating Coating,
	int32 Amount)
{
	if (int32* Count = FlaskInventory.Find(Coating))
	{
		*Count += Amount;
	}
	else
	{
		FlaskInventory.Add(Coating, Amount);
	}
}
