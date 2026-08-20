// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_CampfireRelationshipOverview.h"

void UAshenUserWidget_CampfireRelationshipOverview::UpdateCompanionTrustLevels(float InGarrettTrust, float InSerafinaTrust)
{
	GarrettTrustDisplay = InGarrettTrust;
	SerafinaTrustDisplay = InSerafinaTrust;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_CampfireRelationshipOverview: Updated trust (Garrett=%.2f, Serafina=%.2f)"), GarrettTrustDisplay, SerafinaTrustDisplay);
}
