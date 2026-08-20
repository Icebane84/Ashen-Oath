// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_FinisherWeakspotHUD.h"

void UAshenUserWidget_FinisherWeakspotHUD::DisplayFlankWeakspot(bool bExposed, float Duration)
{
	bIsWeakspotExposed = bExposed;
	ExposureTimeRemaining = Duration;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_FinisherWeakspotHUD: Flank Weakspot (2.5x Multiplier) %s for %.1fs."),
		bIsWeakspotExposed ? TEXT("EXPOSED") : TEXT("CLOSED"), ExposureTimeRemaining);
}
