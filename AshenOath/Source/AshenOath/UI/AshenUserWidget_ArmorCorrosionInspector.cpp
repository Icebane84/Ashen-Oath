// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_ArmorCorrosionInspector.h"

void UAshenUserWidget_ArmorCorrosionInspector::RefreshArmorCorrosionDisplay(float CorrosionLevel)
{
	ArmorCorrosionPercent = FMath::Clamp(CorrosionLevel / 100.0f, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_ArmorCorrosionInspector: Refreshed armor corrosion display to %f%%"), ArmorCorrosionPercent * 100.0f);
}
