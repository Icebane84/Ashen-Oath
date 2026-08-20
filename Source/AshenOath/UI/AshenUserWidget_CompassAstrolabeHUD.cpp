// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_CompassAstrolabeHUD.h"

void UAshenUserWidget_CompassAstrolabeHUD::UpdateAstrolabeDisplay(float InDegrees, ECompassResonanceState InState)
{
	DisplayNeedleDegrees = InDegrees;
	DisplayState = InState;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_CompassAstrolabeHUD: Astrolabe Bearing: %.1f deg (State: %d)"),
		DisplayNeedleDegrees, static_cast<int32>(DisplayState));
}
