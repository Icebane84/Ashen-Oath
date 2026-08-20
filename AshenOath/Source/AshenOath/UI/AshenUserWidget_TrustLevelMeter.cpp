// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 244: Ashen Trust Level Meter UMG Widget

#include "AshenUserWidget_TrustLevelMeter.h"

void UAshenUserWidget_TrustLevelMeter::UpdateTrustDisplay(FName CompanionName, float TrustScore, float SynergyMultiplier)
{
	ActiveCompanionName = CompanionName;
	ActiveTrustScore = TrustScore;
	ActiveSynergyMultiplier = SynergyMultiplier;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_TrustLevelMeter: Companion '%s' Trust: %.1f — Active Synergy Multiplier: %.2fx."),
		*CompanionName.ToString(), TrustScore, SynergyMultiplier);
}
