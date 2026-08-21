// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Crafting/AshenRunicSocketRegistryComponent.h"

UAshenRunicSocketRegistryComponent::UAshenRunicSocketRegistryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenRunicSocketRegistryComponent::InstallRune(ERunicSocketType Slot, const FRunicSocketEntry& Entry)
{
	if (Slot == ERunicSocketType::None || Entry.RuneId == NAME_None)
	{
		return false;
	}

	Sockets.Add(Slot, Entry);
	return true;
}

bool UAshenRunicSocketRegistryComponent::RemoveRune(ERunicSocketType Slot)
{
	return Sockets.Remove(Slot) > 0;
}

bool UAshenRunicSocketRegistryComponent::HasSocketedRune(ERunicSocketType Slot) const
{
	return Sockets.Contains(Slot);
}
