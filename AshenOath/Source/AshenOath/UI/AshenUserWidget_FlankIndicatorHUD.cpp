// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_FlankIndicatorHUD.h"

void UAshenUserWidget_FlankIndicatorHUD::UpdateFlankReticle(bool bAligned, float AngleDegrees)
{
	bIsFlankAligned = bAligned;
	CurrentFlankAngle = AngleDegrees;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_FlankIndicatorHUD: Flank Reticle -> Aligned: %s (Angle: %.1f deg)"),
		bIsFlankAligned ? TEXT("TRUE") : TEXT("FALSE"), CurrentFlankAngle);
}
