// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AAshenSanctuaryReflectionChamberResonanceActor.h"

AAshenSanctuaryReflectionChamberResonanceActor::AAshenSanctuaryReflectionChamberResonanceActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenSanctuaryReflectionChamberResonanceActor::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	ChamberAmbientColor = FMath::Lerp(FLinearColor::Blue, FLinearColor::Red, NewState.Corruption);
	UE_LOG(LogTemp, Log, TEXT("AAshenSanctuaryReflectionChamberResonanceActor: Sanctuary reflection chamber ambient color updated."));
}
