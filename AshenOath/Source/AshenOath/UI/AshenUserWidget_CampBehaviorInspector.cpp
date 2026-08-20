// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 599: Ashen User Widget Camp Behavior Inspector

#include "AshenUserWidget_CampBehaviorInspector.h"

void UAshenUserWidget_CampBehaviorInspector::InspectCampfireCompanions(FName GarrettState, FName SerafinaState, float PartyMoraleLevel)
{
	ActiveGarrettState = GarrettState;
	ActiveSerafinaState = SerafinaState;
	ActivePartyMoraleLevel = PartyMoraleLevel;

	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_CampBehaviorInspector: CAMP INSPECTED -> Garrett: '%s' | Serafina: '%s' | Party Morale: %.2f."),
		*GarrettState.ToString(), *SerafinaState.ToString(), ActivePartyMoraleLevel);
}
