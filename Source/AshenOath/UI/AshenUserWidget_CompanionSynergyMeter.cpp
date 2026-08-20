// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 209: Ashen Companion Synergy Meter UMG Widget

#include "AshenUserWidget_CompanionSynergyMeter.h"

void UAshenUserWidget_CompanionSynergyMeter::UpdateSynergyDisplay(float SynergyPercent, float Multiplier)
{
	CachedSynergyPercent = FMath::Clamp(SynergyPercent, 0.0f, 1.0f);
	CachedMultiplier = Multiplier;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_CompanionSynergyMeter: Synergy meter updated to %.1f%% (Multiplier: %.2fx)."),
		CachedSynergyPercent * 100.0f, CachedMultiplier);
}
