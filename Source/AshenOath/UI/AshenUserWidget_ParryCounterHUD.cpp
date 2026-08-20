// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_ParryCounterHUD.h"

void UAshenUserWidget_ParryCounterHUD::UpdateCombatHUD(bool bParryActive, float EnergyRatio)
{
	bParryWindowActive = bParryActive;
	UnchainedEnergyRatio = FMath::Clamp(EnergyRatio, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_ParryCounterHUD: Parry Window: %s | Unchained Energy: %.1f%%"),
		bParryWindowActive ? TEXT("OPEN") : TEXT("CLOSED"), UnchainedEnergyRatio * 100.0f);
}
