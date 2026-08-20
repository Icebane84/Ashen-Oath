// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 787: Ashen Oathbringer Runic Glow VFX Anchor Actor

#include "AshenOathbringerRunicGlowVFXAnchorActor.h"

AAshenOathbringerRunicGlowVFXAnchorActor::AAshenOathbringerRunicGlowVFXAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsGlowing = false;
}

void AAshenOathbringerRunicGlowVFXAnchorActor::TriggerRunicGlowVFX(float Luminance)
{
	bIsGlowing = true;
	OnRunicGlowTriggered.Broadcast(GetActorLocation(), Luminance);

	UE_LOG(LogTemp, Warning, TEXT("AAshenOathbringerRunicGlowVFXAnchorActor: RUNIC GLOW VFX TRIGGERED -> Location: (%s) | Luminance: %.2f."),
		*GetActorLocation().ToString(), Luminance);
}
