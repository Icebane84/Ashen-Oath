// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_ChestStarburstReticleHUD.h"

void UAshenUserWidget_ChestStarburstReticleHUD::SetReticleVisibility(bool bVisible)
{
	bIsReticleVisible = bVisible;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_ChestStarburstReticleHUD: Chest Starburst Reticle: %s"),
		bIsReticleVisible ? TEXT("ACTIVE") : TEXT("HIDDEN"));
}
