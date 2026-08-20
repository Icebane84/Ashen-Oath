// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_SoulConstellationHUD.h"

void UAshenUserWidget_SoulConstellationHUD::UpdateConstellationDisplay(float NodeDistance)
{
	CurrentNodeDistance = NodeDistance;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_SoulConstellationHUD: Node Distance Display: %.1fuu"),
		CurrentNodeDistance);
}
