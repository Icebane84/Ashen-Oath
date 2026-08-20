// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_SymbioticResonanceHUD.h"

void UAshenUserWidget_SymbioticResonanceHUD::SetHUDResonanceFade(bool bInResonance)
{
	HUDOpacity = bInResonance ? 0.0f : 1.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_SymbioticResonanceHUD: HUD Opacity set to %.2f (Resonance: %s)"),
		HUDOpacity, bInResonance ? TEXT("ACTIVE (UI-LESS)") : TEXT("NORMAL"));
}
