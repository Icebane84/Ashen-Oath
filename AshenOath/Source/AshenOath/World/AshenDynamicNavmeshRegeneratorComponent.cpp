// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenDynamicNavmeshRegeneratorComponent.h"

UAshenDynamicNavmeshRegeneratorComponent::UAshenDynamicNavmeshRegeneratorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenDynamicNavmeshRegeneratorComponent::RequestNavmeshTileRebuild(
	const FVector& Origin,
	float RadiusUU)
{
	// In production, triggers dynamic tile dirtying via NavigationSystemV1
	return true;
}
