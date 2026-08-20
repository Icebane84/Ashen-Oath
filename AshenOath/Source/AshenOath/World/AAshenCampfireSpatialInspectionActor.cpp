// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AAshenCampfireSpatialInspectionActor.h"

AAshenCampfireSpatialInspectionActor::AAshenCampfireSpatialInspectionActor()
{
	PrimaryActorTick.bCanEverTick = false;
	CurrentCompanionFocus = FName(TEXT("CampfireRoot"));
}

void AAshenCampfireSpatialInspectionActor::SelectCompanionFocus(FName CompanionID)
{
	CurrentCompanionFocus = CompanionID;
	UE_LOG(LogTemp, Log, TEXT("AAshenCampfireSpatialInspectionActor: Spatial camera focused on '%s'"), *CurrentCompanionFocus.ToString());
}
