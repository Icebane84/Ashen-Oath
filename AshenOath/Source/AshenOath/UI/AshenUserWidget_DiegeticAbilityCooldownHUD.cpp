// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_DiegeticAbilityCooldownHUD.h"

void UAshenUserWidget_DiegeticAbilityCooldownHUD::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	CooldownPulseOpacity = 0.5f + (NewState.Resolve * 0.5f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_DiegeticAbilityCooldownHUD: Cooldown pulse opacity set to %.2f"), CooldownPulseOpacity);
}
