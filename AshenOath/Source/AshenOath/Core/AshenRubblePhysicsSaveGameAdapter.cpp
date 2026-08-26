// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenRubblePhysicsSaveGameAdapter.h"

UAshenRubblePhysicsSaveGameAdapter::UAshenRubblePhysicsSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	bSavedCollapsed = false;
	bSavedPassageCleared = false;
	SavedRemainingMass = 250.0f;
}

void UAshenRubblePhysicsSaveGameAdapter::PackageRubbleState(
	bool bCollapsed,
	bool bPassageCleared,
	float RemainingMassKg)
{
	bSavedCollapsed = bCollapsed;
	bSavedPassageCleared = bPassageCleared;
	SavedRemainingMass = RemainingMassKg;
	bHasSavedData = true;
}

bool UAshenRubblePhysicsSaveGameAdapter::RestoreRubbleState(
	bool& OutCollapsed,
	bool& OutPassageCleared,
	float& OutRemainingMass)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutCollapsed = bSavedCollapsed;
	OutPassageCleared = bSavedPassageCleared;
	OutRemainingMass = SavedRemainingMass;
	return true;
}
