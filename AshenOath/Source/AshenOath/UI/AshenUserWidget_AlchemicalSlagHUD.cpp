// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_AlchemicalSlagHUD.h"

UAshenUserWidget_AlchemicalSlagHUD::UAshenUserWidget_AlchemicalSlagHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedSoot = 0.0f;
	DisplayedSurfaceState = EOathbringerBladeSurfaceState::PolishedResolve;
	DisplayedCoating = EAlchemicalBladeCoating::None;
	DisplayedCharges = 0;
}

void UAshenUserWidget_AlchemicalSlagHUD::UpdateSlagHUD(
	float SootPercent,
	EOathbringerBladeSurfaceState SurfaceState,
	EAlchemicalBladeCoating Coating,
	int32 RemainingCharges)
{
	DisplayedSoot = SootPercent;
	DisplayedSurfaceState = SurfaceState;
	DisplayedCoating = Coating;
	DisplayedCharges = RemainingCharges;
}
