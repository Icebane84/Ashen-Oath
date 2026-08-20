// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenSanctuaryHearthEmbersResonanceActor.h"

AAshenSanctuaryHearthEmbersResonanceActor::AAshenSanctuaryHearthEmbersResonanceActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenSanctuaryHearthEmbersResonanceActor::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	EmberSpawnRateScalar = 1.0f + (NewState.Resolve * 3.0f);
	UE_LOG(LogTemp, Log, TEXT("AAshenSanctuaryHearthEmbersResonanceActor: Hearth ember spawn rate scalar set to %.2f"), EmberSpawnRateScalar);
}
