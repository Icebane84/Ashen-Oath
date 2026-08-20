// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 359: Ashen Prismatic Veil Overlay UMG Widget

#include "AshenUserWidget_PrismaticVeilOverlay.h"

void UAshenUserWidget_PrismaticVeilOverlay::UpdateVeilOverlayDisplay(EAshenWorldVeilState VeilState, float DissonanceFactor)
{
	DisplayedVeilState = VeilState;
	DisplayedDissonance = DissonanceFactor;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_PrismaticVeilOverlay: Prismatic Veil Overlay updated -> State %d (Dissonance: %.1fx)."),
		(int32)VeilState, DissonanceFactor);
}
