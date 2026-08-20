// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenSanctuaryCrucibleFlameResonanceActor.h"

AAshenSanctuaryCrucibleFlameResonanceActor::AAshenSanctuaryCrucibleFlameResonanceActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenSanctuaryCrucibleFlameResonanceActor::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	CrucibleFlameGlowScalar = 1.0f + (NewState.Resolve * 2.5f);
	UE_LOG(LogTemp, Log, TEXT("AAshenSanctuaryCrucibleFlameResonanceActor: Crucible flame glow scalar set to %.2f"), CrucibleFlameGlowScalar);
}
