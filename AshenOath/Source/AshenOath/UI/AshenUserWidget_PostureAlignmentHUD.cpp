// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_PostureAlignmentHUD.h"

void UAshenUserWidget_PostureAlignmentHUD::UpdatePostureAlignmentGaugeDisplay(float AlignmentScalar)
{
	PostureAlignmentGaugePercent = FMath::Clamp(AlignmentScalar / 2.0f, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_PostureAlignmentHUD: Refreshed posture alignment HUD display to %f%%"), PostureAlignmentGaugePercent * 100.0f);
}
