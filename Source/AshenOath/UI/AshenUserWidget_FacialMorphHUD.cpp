// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 502: Ashen Facial Morph HUD UMG Widget

#include "AshenUserWidget_FacialMorphHUD.h"

void UAshenUserWidget_FacialMorphHUD::UpdateFacialMorphHUDDisplay(float PainWeight, float ExhaustionWeight)
{
	DisplayedPainWeight = PainWeight;
	DisplayedExhaustionWeight = ExhaustionWeight;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_FacialMorphHUD: Facial Morph HUD updated — Pain: %.2f | Exhaustion: %.2f."),
		PainWeight, ExhaustionWeight);
}
