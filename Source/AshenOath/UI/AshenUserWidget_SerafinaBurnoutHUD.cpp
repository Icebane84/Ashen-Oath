// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_SerafinaBurnoutHUD.h"

void UAshenUserWidget_SerafinaBurnoutHUD::UpdateBurnoutHUD(float Burnout, bool bFever)
{
	BurnoutPercentage = FMath::Clamp(Burnout / 100.0f, 0.0f, 1.0f);
	bIsFeverCritical = bFever;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_SerafinaBurnoutHUD: Burnout Gauge: %.1f%% | Fever State: %s"),
		BurnoutPercentage * 100.0f, bIsFeverCritical ? TEXT("CRITICAL") : TEXT("NORMAL"));
}
