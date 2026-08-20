// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_NullZoneThreatHUD.h"

void UAshenUserWidget_NullZoneThreatHUD::UpdateThreatHUD(float Proximity, bool bWarning)
{
	ProximityMeter = FMath::Clamp(Proximity, 0.0f, 1.0f);
	bIsWarningActive = bWarning;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_NullZoneThreatHUD: Proximity %.1f%%, Warning: %s"),
		ProximityMeter * 100.0f, bIsWarningActive ? TEXT("ACTIVE") : TEXT("OFF"));
}
