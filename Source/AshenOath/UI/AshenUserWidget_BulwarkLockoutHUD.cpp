// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_BulwarkLockoutHUD.h"

void UAshenUserWidget_BulwarkLockoutHUD::SetLockoutVisibility(bool bActive)
{
	bIsLockoutActive = bActive;
	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_BulwarkLockoutHUD: Bulwark Lockout Alert: %s (Burnout >= 0.7)"),
		bIsLockoutActive ? TEXT("ACTIVE") : TEXT("CLEARED"));
}
