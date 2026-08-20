// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_IdentityResonanceHUD.h"

void UAshenUserWidget_IdentityResonanceHUD::UpdateIdentityResonanceDisplay(float ResonanceScalar)
{
	IdentityResonanceGaugePercent = FMath::Clamp(ResonanceScalar / 2.0f, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_IdentityResonanceHUD: Refreshed identity resonance HUD display to %f%%"), IdentityResonanceGaugePercent * 100.0f);
}
