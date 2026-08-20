// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 177: Ashen Compass Bar UMG Widget

#include "AshenUserWidget_CompassBar.h"

void UAshenUserWidget_CompassBar::UpdateHeading(float YawDegrees)
{
	// Normalize yaw [-180, 180] or [0, 360] → [0.0, 1.0] scroll offset
	CurrentYaw = FMath::Fmod(YawDegrees + 360.0f, 360.0f);
	CompassScrollOffset = CurrentYaw / 360.0f;
}

FText UAshenUserWidget_CompassBar::GetCardinalDirection() const
{
	// 8-point compass rose
	if (CurrentYaw < 22.5f || CurrentYaw >= 337.5f) return FText::FromString(TEXT("N"));
	if (CurrentYaw < 67.5f)  return FText::FromString(TEXT("NE"));
	if (CurrentYaw < 112.5f) return FText::FromString(TEXT("E"));
	if (CurrentYaw < 157.5f) return FText::FromString(TEXT("SE"));
	if (CurrentYaw < 202.5f) return FText::FromString(TEXT("S"));
	if (CurrentYaw < 247.5f) return FText::FromString(TEXT("SW"));
	if (CurrentYaw < 292.5f) return FText::FromString(TEXT("W"));
	return FText::FromString(TEXT("NW"));
}
