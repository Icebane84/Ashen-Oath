// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 593: Ashen User Widget Companion Divergence Warning

#include "AshenUserWidget_CompanionDivergenceWarning.h"

void UAshenUserWidget_CompanionDivergenceWarning::DisplayCompanionDivergenceWarning(FName CompanionID, float TrustLevel)
{
	ActiveDivergentCompanionID = CompanionID;
	ActiveTrustLevel = TrustLevel;
	DisplayedRiskPercentage = FMath::Clamp((1.0f - (TrustLevel / 100.0f)) * 100.0f, 0.0f, 100.0f);

	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_CompanionDivergenceWarning: COMPANION DIVERGENCE WARNING DISPLAYED -> Companion '%s' (Trust: %.1f)."),
		*CompanionID.ToString(), ActiveTrustLevel);
}

void UAshenUserWidget_CompanionDivergenceWarning::UpdateDivergenceWarning(FName CompanionID, float RiskPercent)
{
	ActiveDivergentCompanionID = CompanionID;
	DisplayedRiskPercentage = FMath::Clamp(RiskPercent, 0.0f, 100.0f);
	ActiveTrustLevel = 100.0f - DisplayedRiskPercentage;
}
