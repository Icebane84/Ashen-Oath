// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_DiegeticStanceIndicatorHUD.h"

void UAshenUserWidget_DiegeticStanceIndicatorHUD::OnSoulStateInvalidated(const FSoulStateVector& StateVector)
{
	StanceIconOpacityFlicker = FMath::Clamp(1.0f - (StateVector.Isolation * 0.4f), 0.4f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_DiegeticStanceIndicatorHUD: Stance icon opacity flicker set to %.2f"), StanceIconOpacityFlicker);
}
