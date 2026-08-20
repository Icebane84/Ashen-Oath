// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AAshenSanctuaryWisdomWellLuminescenceActor.h"

AAshenSanctuaryWisdomWellLuminescenceActor::AAshenSanctuaryWisdomWellLuminescenceActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenSanctuaryWisdomWellLuminescenceActor::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	WellLuminescenceIntensity = 1.0f + (NewState.Resolve * 2.5f);
	UE_LOG(LogTemp, Log, TEXT("AAshenSanctuaryWisdomWellLuminescenceActor: Sanctuary Wisdom Well luminescence intensity set to %.2f"), WellLuminescenceIntensity);
}
