// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenCartographicSurveyBeaconActor.h"

AAshenCartographicSurveyBeaconActor::AAshenCartographicSurveyBeaconActor()
{
	PrimaryActorTick.bCanEverTick = false;
	BeaconSectorName = FName(TEXT("Ruined_Spire_Overlook"));
	bHasBeenSurveyed = false;
}
void AAshenCartographicSurveyBeaconActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenCartographicSurveyBeaconActor::ActivateSurveyBeacon()
{
	if (bHasBeenSurveyed) return false;
	bHasBeenSurveyed = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenCartographicSurveyBeaconActor: SURVEY BEACON ACTIVATED at [%s]! Sector inking unlocked."),
		*BeaconSectorName.ToString());
	return true;
}
