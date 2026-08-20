// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_ThreadSnapWarningHUD.h"

void UAshenUserWidget_ThreadSnapWarningHUD::SetRuptureAlert(bool bActive)
{
	bIsRuptureImminent = bActive;
	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_ThreadSnapWarningHUD: Thread Rupture Warning: %s!"),
		bIsRuptureImminent ? TEXT("CRITICAL") : TEXT("NORMAL"));
}
