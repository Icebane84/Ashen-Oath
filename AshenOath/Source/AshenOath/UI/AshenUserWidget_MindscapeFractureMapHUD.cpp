// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_MindscapeFractureMapHUD.h"

void UAshenUserWidget_MindscapeFractureMapHUD::UpdateFractureMapDisplay(float NewInstabilityIndex)
{
	MapInstabilityPercent = FMath::Clamp(NewInstabilityIndex, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_MindscapeFractureMapHUD: Updated fracture map display to %f%%"), MapInstabilityPercent * 100.0f);
}
