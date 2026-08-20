// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AAshenOathkeeperBladeLuminescenceModulatorActor.h"

AAshenOathkeeperBladeLuminescenceModulatorActor::AAshenOathkeeperBladeLuminescenceModulatorActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenOathkeeperBladeLuminescenceModulatorActor::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	BladeEmissivePulseIntensity = 1.0f + (NewState.Resolve * 4.0f);
	UE_LOG(LogTemp, Log, TEXT("AAshenOathkeeperBladeLuminescenceModulatorActor: Blade emissive pulse intensity set to %.2f"), BladeEmissivePulseIntensity);
}
