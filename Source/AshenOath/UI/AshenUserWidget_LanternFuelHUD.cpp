// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_LanternFuelHUD.h"

void UAshenUserWidget_LanternFuelHUD::UpdateLanternHUD(float Fuel, bool bLitState)
{
	FuelPercentage = FMath::Clamp(Fuel / 100.0f, 0.0f, 1.0f);
	bIsLit = bLitState;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_LanternFuelHUD: Oil Fuel: %.1f%% | Lantern: %s"),
		FuelPercentage * 100.0f, bIsLit ? TEXT("LIT") : TEXT("EXTINGUISHED"));
}
