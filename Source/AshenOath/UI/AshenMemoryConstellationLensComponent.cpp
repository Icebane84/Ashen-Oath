// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 744: Ashen Memory Constellation Lens Component

#include "AshenMemoryConstellationLensComponent.h"

UAshenMemoryConstellationLensComponent::UAshenMemoryConstellationLensComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveLensMode = FName(TEXT("Lens.Grace"));
}

void UAshenMemoryConstellationLensComponent::SelectConstellationLens(FName LensModeTag, float Zoom)
{
	ActiveLensMode = LensModeTag;
	OnLensSelected.Broadcast(ActiveLensMode, Zoom);

	UE_LOG(LogTemp, Warning, TEXT("UAshenMemoryConstellationLensComponent: CONSTELLATION LENS SELECTED -> Mode: '%s' | Zoom Level: %.2fx."),
		*ActiveLensMode.ToString(), Zoom);
}
