// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_PostureAlignmentInspector.h"

void UAshenUserWidget_PostureAlignmentInspector::RefreshPostureAlignmentDisplay(float AlignmentScalar)
{
	PostureAlignmentPercent = FMath::Clamp(AlignmentScalar / 2.0f, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_PostureAlignmentInspector: Refreshed posture alignment display to %f%%"), PostureAlignmentPercent * 100.0f);
}
