// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AAshenSanctuaryConstellationChamberLightActor.h"

AAshenSanctuaryConstellationChamberLightActor::AAshenSanctuaryConstellationChamberLightActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenSanctuaryConstellationChamberLightActor::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	AmbientLightIntensity = 5000.0f + (NewState.Resolve * 5000.0f) - (NewState.Corruption * 2500.0f);
	UE_LOG(LogTemp, Log, TEXT("AAshenSanctuaryConstellationChamberLightActor: Ambient light intensity set to %.2f"), AmbientLightIntensity);
}
