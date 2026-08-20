// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_AlchemicalPouchHUD.h"

void UAshenUserWidget_AlchemicalPouchHUD::UpdatePouchTelemetry(const FAlchemicalInventoryPouch& InPouch)
{
	DisplayPouch = InPouch;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_AlchemicalPouchHUD: Oils: %d | Needles: %d | Smoke: %d | Flares: %d | Caltrops: %d"),
		DisplayPouch.BurningSteelOilVials, DisplayPouch.GloomwoodDampenerNeedles,
		DisplayPouch.SmokeBalmCharges, DisplayPouch.GhostbloomFlares, DisplayPouch.CaltropSupply);
}
