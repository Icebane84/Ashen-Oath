// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_VeilPhaseFilterInspector.h"

void UAshenUserWidget_VeilPhaseFilterInspector::RefreshVeilPhaseFilterDisplay(float FilterValue)
{
	VeilPhaseFilterPercent = FMath::Clamp(FilterValue, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_VeilPhaseFilterInspector: Refreshed veil phase filter display to %f%%"), VeilPhaseFilterPercent * 100.0f);
}
